#include <stdio.h>
#include <string.h>
int mark[63];

void initMark()
{
	int i;
	int no=0;//没电的天数
	int di=0;
	memset(mark,0,sizeof(mark));
	//将停电的天数做标记
	for(i=1;i<63;i+=di+1)
	{
		++di;
		mark[i]=1;
	}
	//计算从i天到8/31天中停电的次数
	for(i=62;i>0;--i)
	{
		if(mark[i] != 0)
		{
			++no;
		}
		mark[i]=no;
	}
}
int getMark(int m,int d)
{
	//注意：只有7、8两月停电
	d=d+(m-7)*31;
	if(d>62)return mark[62];
	else if(d<1)return mark[1];
	else return mark[d];
}
int main()
{
	char input[8];
	int month,day;
	int i;
	initMark();
	while(1)
	{
		gets(input);
		if(strcmp(input,"0/0") == 0)break;
		month=0;
		day=0;
		month=input[0]-48;//获得月
		i=2;
		while(input[i] != 0)//获得天
		{
			day = day*10+input[i]-48;
			++i;
		}
		printf("%d\n",getMark(month,day));
	}
	return 0;
}
