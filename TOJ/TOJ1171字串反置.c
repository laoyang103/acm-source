#include<stdio.h>
#include<string.h>
char str[101];
int main()
{
	int i,j;
	char temp;
	gets(str);
	i=0;
	j=strlen(str)-1;
	while(i<j)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		++i;
		--j;
	}
	puts(str);
	return 0;
}
