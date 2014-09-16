#include <stdio.h>
#include <string.h>

char str[129],subStr[129];

int countSubStr()
{
	int n=0;
	char *pStr=strstr(str,subStr);
	while(pStr != NULL)
	{
		++n;
		pStr=strstr(pStr+1,subStr);
	}
	return n;
}

int main()
{
	gets(str);
	gets(subStr);
	printf("%d\n",countSubStr());
	return 0;
}
