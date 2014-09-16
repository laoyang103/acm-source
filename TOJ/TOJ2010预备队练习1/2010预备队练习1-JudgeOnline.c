#include<stdio.h>
#include<string.h>
char input[256];
int main()
{
	int i,len;
	while(gets(input)!=NULL)
	{
		len=strlen(input);
		for(i=0;i<len;++i)
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
