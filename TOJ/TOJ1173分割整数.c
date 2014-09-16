#include<stdio.h>
int main()
{
	int data,i,t;
	int stack[15];//栈
	int top=0;//栈顶指针
	scanf("%d",&data);
	while(data!= 0)
	{
		stack[top++]=data%10;//每次将个位数入栈
		data/=10;
	}
	while(top > 1)
	{
		printf("%d ",stack[--top]);
	}
	printf("%d\n",stack[0]);
	return 0;
}
