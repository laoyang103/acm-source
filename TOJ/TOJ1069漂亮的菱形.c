#include <stdio.h>
void print(int h)
{
	int i,j,amount,left;
	for(i=1;i<=h;++i)
	{
		if(i<=h/2)
		{
			amount=i*2-1;//ÿ��*�ŵĸ���
		}
		else
		{
			amount=(h-i)*2+1;
		}
		left=(h-amount)/2;//ÿ����벿�ֿո�ĸ���
		for(j=1;j<=h;++j)
		{
			if(j<=left)putchar(' ');
			else if(j<=left+amount)putchar('*');
			else break;
		}
		putchar('\n');
	}
}
int main()
{
	int h;
	while(scanf("%d",&h),h)
	{
		print(h);
	}
	return 0;
}
