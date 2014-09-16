#include <stdio.h>
#include <string.h>
int array[1000];
int memory[1000];//存贮每项的最大和

/*与朴素最长非降子序列类似
* f(i)=max{f(j)+wi } (0<=j<i)
*/
int DP(int n)
{
	int max=0;
	int i,j;
	memset(memory,0,sizeof(memory));
	for(i=0;i<n;++i)
	{
		memory[i]=array[i];
		for(j=i-1;j>=0;--j)
		{
			if(array[i] > array[j])
			{
				if(memory[i] < array[i]+memory[j])
				{
					memory[i]=array[i]+memory[j];
				}
			}
		}
	}
	for(i=0;i<n;++i)
	{
		if(max < memory[i])
		{
			max=memory[i];
		}
	}
	return max;
}
int main()
{
	int n;
	int i;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",array+i);
		}
		printf("%d\n",DP(n));
	}
	return 0;
}
