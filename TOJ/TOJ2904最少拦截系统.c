#include <stdio.h>
#include <string.h>
typedef struct//声明静态链表
{
	int data;
	int next;
}List;
List memory[1000];
int lstIndex;
int Insert(int data)
{
	int prev=0;
	int current=memory[prev].next;
	while(current != 0)
	{
		if(data > memory[current].data)
		{
			if(prev == 0)//链表头元素
			{
				break;
			}
			else
			{
				memory[prev].data=data;
				return 0;
			}
		}
		prev=current;
		current=memory[current].next;
	}
	if(prev != 0)
	{//链表中只有一个元素时
		memory[prev].data=data;
		return 0;
	}
	else
	{
		memory[lstIndex].data=data;
		memory[lstIndex].next=current;
		memory[0].next=lstIndex;
		++lstIndex;
		return 1;
	}
}
int main()
{
	int n,i,max,data;
	while(scanf("%d",&n)==1)
	{
		memory[0].next=0;
		lstIndex=1;
		max=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&data);
			//若当前的拦截系统不能够拦截该导弹时，
			//则新增一个系统，即插入一个新元素，否则修改原有元素。
			max+=Insert(data);
		}
		printf("%d\n",max);
	}
	return 0;
}
