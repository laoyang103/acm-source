/*2���ݶ�ż�����࣬�����ܵĳ�1
**����ÿ�������������log2(n)=t(����ȡ��)�������2^t<n
**2^tΪ�½�
*/
//WA ���ܽ�����ݷ�Χ��С
#include <stdio.h>
#include <math.h>
int mod(int n)
{
	int t=0;
	int exp2=0;
	if(n==1 || n%2==0)return 33;
	t=(int)(log(n)/log(2))+1;
	exp2=1<<t;
	while(t<64)
	{
		if(exp2%n==1)
		{
			break;
		}
		else
		{
			exp2=exp2<<1;
			++t;
		}
	}
	return t;
}
int main()
{
	int n,x;
	while(scanf("%d",&n)==1)
	{
		x=mod(n);
		if(x>64)printf("2^?=%d\n",n);
		else printf("2^%d=%d\n",x,n);
	}
	return 0;
}
