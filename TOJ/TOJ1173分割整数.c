#include<stdio.h>
int main()
{
	int data,i,t;
	int stack[15];//ջ
	int top=0;//ջ��ָ��
	scanf("%d",&data);
	while(data!= 0)
	{
		stack[top++]=data%10;//ÿ�ν���λ����ջ
		data/=10;
	}
	while(top > 1)
	{
		printf("%d ",stack[--top]);
	}
	printf("%d\n",stack[0]);
	return 0;
}
