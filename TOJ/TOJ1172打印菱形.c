#include<stdio.h>
int main()
{
	int n,i,j,right;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		right=n-i+i*2-1;//ср╫Гоч
		for(j=1;j<=right;++j)
		{
			if(j>n-i)putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}
	for(i=n-1;i>0;--i)
	{
		right=n-i+i*2-1;
		for(j=1;j<=right;++j)
		{
			if(j>n-i)putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
