#include <stdio.h>
int memory[31];
void initShip()
{
	int i;
	memory[0]=3;
	for(i=1;i<31;++i)
	{
		memory[i]=(memory[i-1]-1)*2;
	}
}
int getShip(int n)
{
	return memory[n];
}
int main()
{
	int t;
	int n;
	initShip();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",getShip(n));
	}
	return 0;
}
