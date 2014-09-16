#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXPRIM	1000001
int prim[100000]={2,3,5};

void CreatePrim()
{
	int i,j,c=3,sq;
	int di=2;
	for(i=7;i<MAXPRIM;i+=di)
	{
		di=6-di;
		sq=(int)sqrt(i);
		for(j=prim[0];j<=sq;++j)
			if(i%j==0)
				break;
		if(j>sq)
		{
			prim[c++]=i;
		//	printf("%d ",i);
		}
		if(c>100000)break;
	}
	printf("\n%d\n",c);
}
int main()
{
	CreatePrim();
	return 0;
}