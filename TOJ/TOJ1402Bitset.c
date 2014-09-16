//十进制转换到2进制
#include <stdio.h>
int stack[32];
int top;
void toBase2(int n)
{
	top=0;
	while(n != 0)
	{
		stack[top++]=n%2;
		n/=2;
	}
	while(top>0)
	{
		printf("%d",stack[--top]);
	}
	printf("\n");
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		toBase2(n);
	}
	return 0;
}
