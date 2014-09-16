@echo off

set GPPPATH=E:\IMUSTJudge\AcmJudge\bin\gcc\bin\g++.exe
set OUTPUTBIN=D:\outfiles\%2.exe
set LOGFILE=D:\maketest.log
set OUTPUTDIR=D:\outfiles

set SOURCEFILE=%1.cpp
set INFILE=%1.in
set OUTFILE=%OUTPUTDIR%\%2\output\%2.out

if exist %OUTPUTDIR% goto direxist >nul 2>nul
mkdir %OUTPUTDIR% >nul 2>nul
:direxist

del /f /q /s %OUTPUTBIN% >nul 2>nul

%GPPPATH% %SOURCEFILE% -o %OUTPUTBIN% >nul 2>nul

set err=%errorlevel%

if "%err%"=="0" goto success
goto failure

:success
mkdir %OUTPUTDIR%\%2\output >nul 2>nul
%OUTPUTBIN% < %INFILE% > %OUTFILE%
set COPYINFILEPATH=%OUTPUTDIR%\%2\input
mkdir %OUTPUTDIR%\%2\input >nul 2>nul
copy /Y %INFILE% /A  %COPYINFILEPATH% /A >nul 2>nul
goto end

:failure
echo compile %SOURCEFILE% failed
echo compile %SOURCEFILE% failed >> %LOGFILE%

:end

