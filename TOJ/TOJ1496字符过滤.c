#include <stdio.h>
#include <string.h>
int mark[256];
int main()
{
	char str[71];
	char s[71];
	int i;
	unsigned char ch;
	memset(mark,0,sizeof(mark));
	gets(str);
	gets(s);
	i=0;
	ch=s[i];
	while(ch)
	{
		mark[ch]=1;
		++i;
		ch=s[i];
	}
	i=0;
	ch=str[i];
	while(ch != 0)
	{
		if(mark[ch]==0)
		{
			putchar(str[i]);
		}
		++i;
		ch=str[i];
	}
	return 0;
}
