#include<stdio.h>
#include<math.h>
int main()
{	long a,b,t;
	double x;
			x=1.6180339887498949;
		while(scanf("%d%d",&a,&b)!=EOF)
			{	if(a>b) {t=a;a=b;b=t;}
				if(floor(x*(b-a))==a) printf("0\n");
				else printf("1\n");
			}
	return 0;
}

