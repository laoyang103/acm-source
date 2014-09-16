#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define size 3200
int pm[446] = {2,3,5};//������
int total = 3;//���������������ܸ���
int abc;//�������
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
//�۰����
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
	//û���ҵ����򷵻�С�ڸ���������������±�+1��
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
	
	total=creat_prime(pm,3162,total);//����1-3162֮�������������������������
	while (scanf("%d", &abc), abc)
	{
		total = B((int)(sqrt(abc) + 0.5));//����������ݵĿ����������۰���ҡ�
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
