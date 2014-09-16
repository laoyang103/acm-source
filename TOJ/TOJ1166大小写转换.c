#include<stdio.h>
int main()
{
	char input[81];
	int i=0;
	gets(input);
	while(input[i])
	{
		if(input[i]>64 && input[i]<91)input[i]+=32;
		else if(input[i]>96 && input[i]<123)input[i]-=32;
		++i;
	}
	puts(input);
	return 0;
}
