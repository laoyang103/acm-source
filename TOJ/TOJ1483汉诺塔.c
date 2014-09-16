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
		Han(n-1,a,c,b);//将前n-1个盘子借助于c移动到b
		Move(n,a,c);//将第n个盘子从a移动到c
		Han(n-1,b,a,c);//将前n-1个盘子借助于a移动到c
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	Han(n,'A','B','C');
	return 0;
}
