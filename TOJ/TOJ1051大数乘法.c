#include <stdio.h>
#include <string.h>
int opr1[101];//两个操作数
int opr2[101];
int result[202];//计算结果
char input1[101];//两个输入数据
char input2[101];
int main()
{
	int n,count=0;
	int len1,len2;
	int i,j;
	scanf("%d",&n);
	while(++count<=n)
	{
		memset(result,0,sizeof(result));
		scanf("%s",input1);
		len1=strlen(input1);
		for(i=0;i<len1;++i)
			opr1[101-len1+i]=input1[i]-48;
		scanf("%s",input2);
		len2=strlen(input2);
		for(i=0;i<len2;++i)
			opr2[101-len2+i]=input2[i]-48;
		for(i=100;i>100-len1;--i)
		{
			for(j=100;j>100-len2;--j)
			{
				result[i+j+1]+=opr1[i]*opr2[j];
			}
		}
		for(i=201;i>0;--i)
		{
			result[i-1]+=result[i]/10;
			result[i]=result[i]%10;
		}
		printf("Case %d:\n",count);
		printf("%s * %s = ",input1,input2);
		for(i=0;i<202;++i)
			if(result[i]!=0)
				break;
		if(i<202)
		{
			for(j=i;j<202;++j)
				printf("%d",result[j]);
		}
		else printf("0");
		printf("\n");
		if(count!=n)
			printf("\n");
	}
	return 0;
}
