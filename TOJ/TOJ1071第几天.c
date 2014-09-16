#include <stdio.h>
int month_days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void LeapYear(int year)//求闰年
{
	if((year%4==0 && year%100!=0)||(year%400==0))
	{
		month_days[2]=29;
	}
	else
	{
		month_days[2]=28;
	}
}
int fn(char* input)
{
	int year,month,day,temp,i;
	for(year=0,i=0;i<4;++i)//获得年
	{
		year=year*10+input[i]-48;
	}
	month=(input[5]-48)*10+input[6]-48;//获得月
	day=(input[8]-48)*10+input[9]-48;//获得日
	LeapYear(year);
	for(temp=0,i=1;i<month;++i)
	{
		temp+=month_days[i];
	}
	temp+=day;
	return temp;
}
int main()
{
	char input[11];
	while(gets(input))
	{
		printf("%d\n",fn(input));
	}
	return 0;
}
