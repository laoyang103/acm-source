#include <stdio.h>
int main()
{
	int a,b;
	int tail;
	while(1)
	{
		tail=1;
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)break;
		a*=100;
		if(a%b==0)
		{
			printf("00");
			tail=0;
		}
		else
		{
			tail=b*(a/b+1)-a;
			printf("%2.2d",tail);
		}
		for(tail+=b;tail<100;tail+=b)
		{
			printf(" %2.2d",tail);
		}
		printf("\n");
	}
	return 0;
}
