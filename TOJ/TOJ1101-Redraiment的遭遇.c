#include <stdio.h>
#include <string.h>
int mark[63];

void initMark()
{
	int i;
	int no=0;//û�������
	int di=0;
	memset(mark,0,sizeof(mark));
	//��ͣ������������
	for(i=1;i<63;i+=di+1)
	{
		++di;
		mark[i]=1;
	}
	//�����i�쵽8/31����ͣ��Ĵ���
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
	//ע�⣺ֻ��7��8����ͣ��
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
		month=input[0]-48;//�����
		i=2;
		while(input[i] != 0)//�����
		{
			day = day*10+input[i]-48;
			++i;
		}
		printf("%d\n",getMark(month,day));
	}
	return 0;
}
