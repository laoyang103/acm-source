#include <stdio.h>
void Move(int n,char a,char b)
{
	printf("Move disk %d from %c to %c\n",n,a,b);
}
void Han(int n,char a,char b,char c)
{
	if(n==1)
	{
		Move(n,a,c);
	}
	else
	{
		Han(n-1,a,c,b);//��ǰn-1�����ӽ�����c�ƶ���b
		Move(n,a,c);//����n�����Ӵ�a�ƶ���c
		Han(n-1,b,a,c);//��ǰn-1�����ӽ�����a�ƶ���c
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	Han(n,'A','B','C');
	return 0;
}
