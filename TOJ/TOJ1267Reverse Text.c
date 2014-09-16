#include <stdio.h>
#include <string.h>
char* rollString(char *str)//·­×ª×Ö·û´®
{
	int left=0;
	int right=strlen(str)-1;
	char temp;
	while(left<right)
	{
		temp=str[left];
		str[left]=str[right];
		str[right]=temp;
		++left;
		--right;
	}
	return str;
}
int main()
{
	int n;
	char str[128];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		puts(rollString(gets(str)));
	}
	return 0;
}
