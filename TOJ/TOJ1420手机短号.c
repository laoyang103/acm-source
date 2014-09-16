#include <stdio.h>
#include <string.h>
char* GetShortNumber(char *dest,char *src)
{
	dest[0]='6';
	memcpy(dest+1,src+6,5*sizeof(char));
	dest[6]=0;
	return dest;
}
int main()
{
	int n;
	char phoneNumber[12];
	char shortNumber[7];
	scanf("%d\n",&n);
	while(n--)
	{
		gets(phoneNumber);
		puts(GetShortNumber(shortNumber,phoneNumber));
	}
	return 0;
}
