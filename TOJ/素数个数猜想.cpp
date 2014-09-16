#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define size 3200
int pm[446] = {2,3,5};//素数表
int total = 3;//素数表中素数的总个数
int abc;//输入的数
int num;
int Len;
void R(int n, int b, int sum)
{
	if (n < Len)
	{
		int i, tmp;
		for (i = b; i < total - Len + 1 + n; i++)
		{
			tmp = num;
			R(n + 1, i + 1, sum * pm[i]);
			if (tmp == num)
				return;
		}
	}
	else
	{
		num += abc / sum;
	}
}
//折半查找
int B(int len)
{
	int left = 0;
	int right = 445;
	int middle;

	while (left < right)
	{
		middle = (left + right) / 2;
		if (pm[middle] > len)
			right = middle - 1;
		else if (pm[middle] < len)
			left = middle + 1;
		else
			return middle + 1;
	}
	//没有找到。则返回小于该数的最大素数的下标+1。
	return pm[left] <= len ? left + 1 : left;
}
int creat_prime(int prime[],int n,int total)
{
	int i, j;
	int gab=2;
	int count;
	for(i=7;i<=n;i+=gab)
	{
		count=1;
		gab=6-gab;
		for(j=0;prime[j]*prime[j]<=i;j++)
		{
			if(i%prime[j]==0)
			{
				count=0;
				break;
			}
		}
		if(count)
		{
			prime[total]=i;
			total++;
		}
	}
	return total;
}

int main(void)
{
	int len;
	int count = 2;
	
	total=creat_prime(pm,3162,total);//生成1-3162之间的所有素数，返回素数个数
	while (scanf("%d", &abc), abc)
	{
		total = B((int)(sqrt(abc) + 0.5));//对输入的数据的开方数进行折半查找。
		for (len = 0, Len = 1; Len <= total; Len++)
		{
			num = 0;
			R(0, 0, 1);
			if (!num) break;
			Len % 2 ? (len -= num) : (len += num);
		}
		printf("%d\n", total - 1 + abc + len);
	}
	return 0;
}
