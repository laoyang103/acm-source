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
/*一道水题，题坑害了我半天，
当不能够均分成3堆得时候，要称量最多的那一堆或两堆,因为要考虑最坏情况。
*/