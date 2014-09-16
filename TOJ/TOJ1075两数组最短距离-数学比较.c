#include<stdio.h>
#include<math.h>
int array1[1000];
int array2[1000];
int main()
{
	int m,n;
	int result=0;
	int i=0,j=0;
	int temp;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i)
		scanf("%d",array1+i);
	for(i=0;i<n;++i)
		scanf("%d",array2+i);
	i=0;
	j=0;
	result=100000000;
	while(i<m && j<n)
	{
		temp=abs(array1[i]-array2[j]);
		if(result>temp)result=temp;
		if(array1[i]>array2[j]) ++j;
		else ++i;
	}
	printf("%d\n",result);
	return 0;
}
