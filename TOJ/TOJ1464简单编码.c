#include <stdio.h>
char map[]="9876543210";
int main()
{
	char str[101],t;
	int i=0,j=0;
	gets(str);
	while(str[i])
	{
		if(str[i]>=48 && str[i]<58)str[i]=map[str[i]-48];
		else if(str[i]>=65 && str[i]<91)str[i]+=32;
		else if(str[i]>=97 && str[i]<123)str[i]-=32;
		++i;
	}
	i-=1;
	while(j<i)
	{
		t=str[j];
		str[j]=str[i];
		str[i]=t;
		++j;
		--i;
	}
	puts(str);
	return 0;
}
