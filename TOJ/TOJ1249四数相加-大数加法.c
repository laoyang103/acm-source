#include <stdio.h>
#include <string.h>
#include <math.h>
char result[2011];//��Ž����0�±��Ӧ���λ
int len;//result����Ч�����ݳ���
char str[2011];//����������ݣ�0�±��Ӧ���λ
void add()//�ӷ���result=result+str
{
	int i,j;
	char c=0;//��λ
	char temp;
	for(i=0,j=strlen(str)-1;j>=0;++i,--j)
	{
		temp=c+result[i]+str[j]-48;
		result[i]=temp%10;
		c=temp/10;//���λ�Ľ�λ
	}
	while(c!=0)//�����λ
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
