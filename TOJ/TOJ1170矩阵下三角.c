#include<stdio.h>
int main()
{
	int n,i,j,input,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&input);
			if(j<=i)
			{
				sum+=input;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}
