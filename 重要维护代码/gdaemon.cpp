// ddd.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

#define LOGFILE "D:\\memstatus.txt"

SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE hStatus;

void ServiceMain(int argc, char** argv);
void ControlHandler(DWORD request);
int InitService();

int WriteToLog(char* str)
{
    FILE* log;
    log = fopen(LOGFILE, "a+");
    if (log == NULL)
    return -1;
    fprintf(log, "%s\n", str);
    fclose(log);
    return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR     lpCmdLine,
					 int       nCmdShow)
{
    SERVICE_TABLE_ENTRY ServiceTable[2];
    ServiceTable[0].lpServiceName = "MemoryStatus";
    ServiceTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;
    
    ServiceTable[1].lpServiceName = NULL;
    ServiceTable[1].lpServiceProc = NULL;

    StartServiceCtrlDispatcher(ServiceTable); 

	return 0;
}

void myEnumWindow(HWND inHwnd)
{
	char szText[256];

	HWND hwndAfter = NULL;
	while(hwndAfter = ::FindWindowEx(inHwnd,hwndAfter,NULL,NULL))
	{
		::SendMessage(hwndAfter,WM_GETTEXT,(WPARAM)256,(LPARAM)szText);
		if (0 == strcmp("ºöÂÔ(&I)", szText))
		{
			::SendMessage(hwndAfter, WM_LBUTTONDOWN, 0, 0);
			::Sleep(10);
			::SendMessage(hwndAfter, WM_LBUTTONUP, 0, 0);
			break;
		}
		myEnumWindow(hwndAfter);
	}
}

int startFunc()
{
	HWND win=FindWindow(NULL,"Microsoft Visual C++ Debug Library"); 
	
	if (!win)
		return 0;
	
	myEnumWindow(win);

	return 0;
}

void ServiceMain(int argc, char** argv) 
{
	BOOL bRet;

	bRet = TRUE;
	ServiceStatus.dwServiceType     =SERVICE_WIN32; 
	ServiceStatus.dwCurrentState     =SERVICE_START_PENDING; 
	ServiceStatus.dwControlsAccepted   =SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
	ServiceStatus.dwWin32ExitCode    = 0; 
	ServiceStatus.dwServiceSpecificExitCode = 0; 
	ServiceStatus.dwCheckPoint     = 0;
	ServiceStatus.dwWaitHint     = 0; 
	hStatus = RegisterServiceCtrlHandler("SERVICENAME", (LPHANDLER_FUNCTION)ControlHandler);
	
	if (hStatus == (SERVICE_STATUS_HANDLE)0) 
	{
	   return;
	}

	ServiceStatus.dwCurrentState = SERVICE_RUNNING; 
	SetServiceStatus (hStatus, &ServiceStatus);


	while (ServiceStatus.dwCurrentState == SERVICE_RUNNING)
	{
		int result = startFunc();
		if (result)
		{
		 ServiceStatus.dwCurrentState = SERVICE_STOPPED; 
		 ServiceStatus.dwWin32ExitCode = -1; 
		 SetServiceStatus(hStatus, &ServiceStatus);
		 return;
		}
	}


	return;
}

void ControlHandler(DWORD request) 
{ 
   switch(request) 
   { 
      case SERVICE_CONTROL_STOP: 

         ServiceStatus.dwWin32ExitCode = 0; 
         ServiceStatus.dwCurrentState = SERVICE_STOPPED; 
         SetServiceStatus (hStatus, &ServiceStatus);
         return; 

      case SERVICE_CONTROL_SHUTDOWN: 

         ServiceStatus.dwWin32ExitCode = 0; 
         ServiceStatus.dwCurrentState = SERVICE_STOPPED; 
         SetServiceStatus (hStatus, &ServiceStatus);
         return; 

    default:
         break;
    } 

    SetServiceStatus (hStatus, &ServiceStatus);

    return; 
}

