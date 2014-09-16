#include <stdio.h>
void Swap(char *a,char *b)
{
	char t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	char str[4];
	char t;
	while(gets(str) != NULL)
	{
		if(str[0] > str[1])
		{
			Swap(str,str+1);
		}
		if(str[0] > str[2])
		{
			Swap(str,str+2);
		}
		if(str[1] > str[2])
		{
			Swap(str+1,str+2);
		}
		printf("%c %c %c\n",str[0],str[1],str[2]);
	}
	return 0;
}
