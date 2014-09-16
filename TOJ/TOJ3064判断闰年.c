#include <stdio.h>
int IsLeapYear(int y)//ÊÇ·ñÎªÈòÄê
{
	if(((y%4 == 0) && (y%100 != 0)) || (y%400 == 0))
	{
		return 1;
	}
	else return 0;
}
int main()
{
	int year;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&year);
		if(IsLeapYear(year) == 1)
		{
			puts("Yes");
		}
		else 
		{
			puts("No");
		}
	}
	return 0;
}
