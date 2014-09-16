#include<stdio.h>
int array1[1000];
int array2[1000];
int main()
{
	int m,n;
	int count=0;
	int i=0,j=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i)
		scanf("%d",array1+i);
	for(i=0;i<n;++i)
		scanf("%d",array2+i);
	i=0;
	j=0;
	while(i<m && j<n)
	{
		if(array1[i]>array2[j])
		{
			count+=m-i;
			++j;
		}
		else
		{
			++i;
		}
	}
	printf("%d\n",count);
}
