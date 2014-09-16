#include <stdio.h>
#include <string.h>
#include <math.h>
char result[2011];//存放结果，0下标对应最低位
int len;//result中有效的数据长度
char str[2011];//存放输入数据，0下标对应最高位
void add()//加法，result=result+str
{
	int i,j;
	char c=0;//进位
	char temp;
	for(i=0,j=strlen(str)-1;j>=0;++i,--j)
	{
		temp=c+result[i]+str[j]-48;
		result[i]=temp%10;
		c=temp/10;//向高位的进位
	}
	while(c!=0)//计算进位
	{
		temp=c+result[i];
		result[i]=temp%10;
		c=temp/10;
		++i;
	}
	if(i>len)len=i;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		len=0;
		memset(result,0,sizeof(result));
		for(i=0;i<4;++i)
		{
			scanf("%s",str);
			add();
		}
		for(i=len-1;i>=0;--i)
		{
			printf("%d",result[i]);
		}
		printf("\n");
	}
	return 0;
}
