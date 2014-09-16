#include<stdio.h>
int main()
{
	float sum=0.0f;
	int i;
	for(i=1;i<=100;++i)
	{
		if(i%2!=0)sum+=1.0f/(float)i;
		else sum-=1.0f/(float)i;
	}
	printf("%f",sum);
	return 0;
}
