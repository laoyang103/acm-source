#include<stdio.h>
int main()
{
	int n;//头
	int m;//脚
	int x;//鸽子数
	int y;//兔子数
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n+m==0)
			break;
		/*需注意约束条件,脚的数量为偶数，
		且脚的数量不能大于头的4倍，
		并且脚的数量不能少于头的2倍。*/
		if((m%2!=0)||(m<2*n)||(m>4*n))
			printf("Error\n");
		else
		{
			y=(m-n*2)/2;
			x=n-y;
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}