#include<stdio.h>
#include<string.h>
int prim[201];
int main()
{
	int i,j;
	memset(prim,-1,sizeof(prim));
	for(i=2;i<=15;++i)
		if(prim[i])
			for(j=i*2;j<=200;j+=i)
				prim[j]=0;
	for(j=0,i=100;i<=200;++i)
		if(prim[i])
			++j;
	printf("%d\n",j);
	for(i=100;i<200;++i)
		if(prim[i])
			printf("%d ",i);
	printf("199\n");
	return 0;
}