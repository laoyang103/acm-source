#include<stdio.h>
#include<math.h>
int array1[1000];
int main()
{
	int m,n;
	int result=0;
	int i=0,j=0;
	int temp;
	int input;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i)
		scanf("%d",array1+i);
	scanf("%d",&input);
	i=0;
	j=0;
	result=100000000;
	while(i<m)
	{
		temp=abs(array1[i]-input);
		if(result>temp)result=temp;
		if(array1[i]>input)
		{
			if(++j>n)break;
			scanf("%d",&input);
		}
		else ++i;
	}
	printf("%d\n",result);
	return 0;
}
