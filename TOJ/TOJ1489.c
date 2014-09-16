#include<stdio.h>
int main()
{
	char str[6];
	int i;
	scanf("%s",str);
	for(i=0;i<5;++i)
	{
		str[i]+=4;
	}
	printf("password is %s",str);
	return 0;
}
