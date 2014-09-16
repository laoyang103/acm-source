#include <stdio.h>
int main()
{
	char input[6];
	while(1)
	{
		gets(input);
		if('0' == input[0])
		{
			break;
		}
		if((input[0] == input[4])&&
			(input[1] == input[3]))
		{
			puts("Yes.");
		}
		else
		{
			puts("No.");
		}
	}
	return 0;
}
