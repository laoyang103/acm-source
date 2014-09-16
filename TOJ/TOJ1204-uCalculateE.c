#include <stdio.h>
char headStr[]="n e\n- -----------\n0 1\n1 2\n2 2.5";
void getE()
{
	int i=0;
	int ij;
	double e;
	puts(headStr);
	ij=1;
	e=1.0;
	for(i=1;i<=9;++i)
	{
		ij *= i;//Çó½×³Ë
		e += 1.0/(double)ij;
		if(i>=3)
			printf("%d %.9lf\n",i,e);
	}
}
int main()
{
	getE();
	return 0;
}
