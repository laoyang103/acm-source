#include <stdio.h>
#include <math.h>
int main()
{
	int count,i,j;
	int card;
	int temp;
	int move;
	int t;
	scanf("%d",&count);
	while(count--)
	{
		scanf("%d",&card);
		temp=(int)sqrt(card*2)-3;
		while(!(2*card>=(temp-1)*(temp+2) && 2*card<temp*(temp+3)))++temp;
		move=temp;
		if(2*card!=temp*(temp+3))
			move=temp-1;
		t=move;
		printf("%d 1",++t);
		for(i=2;i<=temp;++i)
		{
			for(j=0;j<i && t<card;++j)
			{
				printf(" %d",++t);
			}
			if(i<=move)
				printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}