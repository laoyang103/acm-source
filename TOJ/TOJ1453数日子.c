#include <stdio.h>
int daysOfMonth[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int IsLeapYear(int y)//是否为闰年
{
	if(((y%4 == 0) && (y%100 != 0)) || (y%400 == 0))
	{
		return 1;
	}
	else return 0;
}
int GetDay(int y,int m,int d)//获得是第几天
{
	int i;
	int day;
	if(1 == IsLeapYear(y))
	{
		daysOfMonth[2]=29;
	}
	else
	{
		daysOfMonth[2]=28;
	}
	day=d;
	for(i=1;i<m;++i)
	{
		day+=daysOfMonth[i];
	}
	return day;
}
int main()
{
	int year,month,day;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&year,&month,&day);
		printf("%d\n",GetDay(year,month,day));
	}
	return 0;
}
