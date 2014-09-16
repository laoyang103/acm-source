#include<stdio.h>
int array1[1000];
int main()
{
	int m,n;
	int count=0;
	int i=0,j=0;
	int input;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i)
		scanf("%d",array1+i);
	scanf("%d",&input);
	i=0;
	j=0;
	while(i<m)
	{
		if(array1[i]<input)++i;
		else 
		{
			if(array1[i]==input)
			{
				++count;
				++i;
			}
			++j;
			if(j>=n) break;
			scanf("%d",&input);
		}
	}
	printf("%d\n",count);
}
