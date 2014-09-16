#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int find(int c)
{
	if(c <= 1)
	{
		 return 0;
	}
	if(c <= 3)
	{
		 return 1;
	}
	//将假币分成 3堆
	else if(c % 3 == 0)//刚好整分
	{
	  return find(c/3)+1;
	}
	else//有余数时，判断 c/3 与 c/3+1的最大比较次数
	{//由于find(c/3)一定小于find(c/3+1),此处可以直接写成 return find(c/3+1)+1；
		return max(find(c/3),find(c/3+1))+1;
	}
}
int main()
{
 	int coin;
 	while(1)
	{
		scanf("%d",&coin);
		if(0 == coin)
		{
		 	 break;
		}
		printf("%d\n",find(coin));
	}
	system("pause");
	return 0;
} 
