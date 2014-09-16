#include <stdio.h>
#include <math.h>
int main()
{
	int max;
	int n;
	int i;
	int input;
	scanf("%d%d",&n,&input);
	max=input;
	for(i=1;i<n;++i)
	{
		scanf("%d",&input);
		if(abs(max) < abs(input))
		{
			max=input;
		}
	}
	printf("%d",max);
}
