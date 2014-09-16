#include<stdio.h>
int main()
{
	int n,right,i,j,counter;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		right=2*n-(2*i-1);//空格右界
		for(j=1;j<right;++j) printf(" ");
		counter=1;
		right=n-i+2*i-1;//数字右界
		for(j=n-i+1;j<right;++j)
		{
			printf("%d ",counter);
			if(j>=n)--counter;
			else ++counter;
		}
		printf("%d",counter);
		printf("\n");
	}
	return 0;
}
