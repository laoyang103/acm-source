#include <stdio.h>
#include <string.h>
char* Convert(char *destStr,char *srcStr)
{
	int i=0;
	int isLastNum=1;//记录上次处理的是否是数字字符
	char *p=srcStr;
	char c=*p;
	while(c != 0)
	{
		if((c >= 48) && (c <58) )//是数字字符
		{
			destStr[i++]=c;
			isLastNum=1;
		}
		else//字符
		{
			if(1 == isLastNum)
			{
				destStr[i++]='*';
				isLastNum=0;
			}
		}	
		++p;
		c=*p;
	}
	destStr[i]=0;
	return destStr;
}
int main()
{
	char str[81];
	char result[81];
	gets(str);
	puts(Convert(result,str));
	return 0;
}
/*
今日得出结论*p的访问速度比较慢，如果程序中多次出现*p，
则可以使用一个变量记录*p的值，则可以提高一定的速度。
*/
