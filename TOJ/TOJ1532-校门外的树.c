#include <stdio.h>
#include <string.h>

char tree[10001]={0};

void mark(int s,int e)//�������ڵ������
{
	int i;
	for(i=s;i<=e;++i)
	{
		tree[i]=1;
	}
}
int count(int n)//ͳ��ʣ�����ĸ���
{
	int i=0;
	int c=0;
	for(i=0;i<=n;++i)
	{
		if(tree[i] == 0)
		{
			++c;
		}
	}
	return c;
}
int main()
{
	int n,t;
	int i;
	int start,end;
	scanf("%d%d",&n,&t);
	for(i=0;i<t;++i)
	{
		scanf("%d%d",&start,&end);
		mark(start,end);
	}
	printf("%d\n",count(n));
	return 0;
}
