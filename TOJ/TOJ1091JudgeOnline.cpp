#include<stdio.h>
#include<string.h>
char input[256];
int main()
{
	while(gets(input)!=NULL)
	{
		int len=strlen(input);
		for(int i=0;i<len;++i)
		{
			if(input[i]=='<')
				printf("&lt;");
			else if(input[i]=='>')
				printf("&gt;");
			else if(input[i]==' ')
				printf("&nbsp;");
			else if(input[i]=='\t')
				printf("&#9;");
			else putchar(input[i]);
		}
		putchar('\n');
	}
	return 0;
}