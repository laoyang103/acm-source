#include <stdio.h>
#include <string.h>
int memory[1000];
int is_sxh(int d)
{
	int a,b,c;
	if(memory[d]==-1)
	{
		a=d/100;
		b=(d%100)/10;
		c=d%10;
		if(a*a*a+b*b*b+c*c*c == d)memory[d]=1;
		else memory[d]=0;
	}
	return memory[d];
}
int main()
{
	int a,b,is_null;
	memset(memory,-1,sizeof(memory));
	while(scanf("%d%d",&a,&b)==2)
	{
		is_null=1;
		for(;a<=b;++a)
		{
			if(is_sxh(a))
			{
				if(is_null)
				{
					printf("%d",a);
					is_null=0;
				}
				else printf(" %d",a);
			}
		}
		if(is_null)printf("no");
		printf("\n");
	}
	return 0;
}
