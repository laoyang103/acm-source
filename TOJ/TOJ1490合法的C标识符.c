#include <stdio.h>
int IsNameValid(char *str)
{
	char ch=*str;
	int isValid=1;
	if(ch>=48 && ch <58)
	{
		isValid=0;
	}
	while((ch != 0) && (isValid == 1))
	{
		if((ch=='_') || (ch>=48 && ch<=57) 
			|| (ch>=65 && ch <=90) || (ch>=97 && ch<=122))
		{
			isValid=1;
		}
		else isValid=0;
		++str;
		ch=*str;
	}
	return isValid;
}
int main()
{
	char name[256];
	gets(name);
	if(IsNameValid(name))
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}
