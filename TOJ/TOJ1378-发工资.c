#include <stdio.h>
int main()
{
	int n,i;
	int salary;
	int sum;
	while(scanf("%d",&n),n)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&salary);
			sum += salary/100;
			salary %= 100;
			sum += salary/50;
			salary %= 50;
			sum += salary/10;
			salary %= 10;
			sum += salary/5;
			salary %= 5;
			sum += salary/2;
			salary %= 2;
			sum += salary;
		}
		printf("%d\n",sum);
	}
	return 0;
}
