#include <stdio.h>
#include <string.h>
int intTime1[3];
int intTime2[3];
char time[10];
void GetIntTime(char *t,int *intTime)
{
	int i=0;
	intTime[i]=0;
	while(*t)
	{
		if(':' == *t)
		{
			++i;
			intTime[i]=0;
		}
		else
		{
			intTime[i]=intTime[i]*10+(*t)-48;
		}
		++t;
	}
}
char* Sub(char *t1,char *t2)
{
	int i,j;
	GetIntTime(t1,intTime1);
	GetIntTime(t2,intTime2);
	for(i=2;i>=0;--i)
	{
		intTime1[i]-=intTime2[i];
		if(intTime1[i] < 0)
		{
			intTime1[i]+=60;
			intTime1[i-1]-=1;
		}
	}
	if(intTime1[0]>=10)
	{
		for(i=j=0;j<3;++j)
		{
			time[i++]=intTime1[j]/10+48;
			time[i++]=intTime1[j]%10+48;
			time[i++]=':';
		}
		time[8]=0;
	}
	else
	{
		time[0]=intTime1[0]+48;
		time[1]=':';
		for(i=2,j=1;j<3;++j)
		{
			time[i++]=intTime1[j]/10+48;
			time[i++]=intTime1[j]%10+48;
			time[i++]=':';
		}
		time[7]=0;
	}
	return time;
}
int main()
{
	char time1[10];
	char time2[10];
	int cmp;
	gets(time1);
	gets(time2);
	cmp=strcmp(time1,time2);
	if(cmp>=0)
	{
		puts(Sub(time1,time2));
	}
	else
	{
		puts(Sub(time2,time1));
	}
	return 0;
}
