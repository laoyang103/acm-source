#include <stdio.h>
#include <ctype.h>
#include <string.h>
char* parse(char *str)//·ÖÎö×Ö·û´®
{
	int i;
	char ch;
	for(i=strlen(str)-1;i>=0;--i)
	{
		ch=str[i];
		if(islower(ch))
		{
			if(ch+6 > 'z')
			{
				ch='a'-1+ch+6-'z';
			}
			else ch+=6;
			str[i]=ch;
		}
	}
	return str;
}
int main()
{
	char str[128];
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(str);
		puts(parse(str));
	}
	return 0;
}
