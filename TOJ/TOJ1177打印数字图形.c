#include<stdio.h>
int main()
{
	int n,right,i,j,counter,k;
	scanf("%d",&n);
	for(i=1;i<n*2;++i)
	{
		counter=1;
		if(i<=n) k=i;
		else k=2*n-i;
		right=n+k-1;
		for(j=0;j<right;++j)
		{
			if(j < n-k)printf(" ");
			else
			{
				printf("%d",counter);
				if(j>=n-1)--counter;
				else ++counter;
			}
		}
		printf("\n");
	}
	return 0;
}
