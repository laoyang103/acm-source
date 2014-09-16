#include <stdio.h>
int main()
{
	int countNagtive,countZero;
	int n,i;
	double data;
	while(scanf("%d",&n),n)
	{
		countNagtive=0;
		countZero=0;
		for(i=0;i<n;++i)
		{
			scanf("%lf",&data);
			if(data < 0)++countNagtive;
			else if(data == 0)++countZero;
		}
		printf("%d %d %d\n",countNagtive,countZero,
				n-countNagtive-countZero);
	}
	return 0;
}
