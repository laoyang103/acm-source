#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	while(1)
	{
		printf("%d\n",a+b);
		scanf("%d%d",&a,&b);
		if(!(a||b))
			break;
		else
			printf("\n");
	}
	return 0;
}