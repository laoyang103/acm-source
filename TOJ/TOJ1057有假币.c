#include <stdio.h>
int func(int n)
{
	if(n<=1)
		return 0;
	if(n<=3)
		return 1;
	return func(n/3+(n%3==0?0:1))+1;
}
int main()
{
	int coin;
	while(scanf("%d",&coin),coin)
		printf("%d\n",func(coin));
	return 0;
}
/*һ��ˮ�⣬��Ӻ����Ұ��죬
�����ܹ����ֳ�3�ѵ�ʱ��Ҫ����������һ�ѻ�����,��ΪҪ����������
*/