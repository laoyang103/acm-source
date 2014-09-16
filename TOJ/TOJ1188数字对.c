#include <stdio.h>
int array[100];
int length;
int counter(int m,int n)
{
	int i;
	int c=0;
	for(i=0;i<length-1;++i)
	{
		if(array[i]==m && array[i+1]==n)
		{
			++c;
		}
	}
	return c;
}
int main()
{
	int a,b;
	int n,i;
	int t;
	scanf("%d",&length);
	for(i=0;i<length;++i)
	{
		scanf("%d",array+i);
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		t=counter(a,b);
		if(t==0)puts("Not Found!");
		else printf("(%d,%d)=%d\n",a,b,t);
	}
	return 0;
}
