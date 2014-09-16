#include <stdio.h>
int main()
{
	int result[32];
	int index;
	int data,r;
	while(scanf("%d%d",&data,&r)!=EOF)
	{
		if(data < 0)
		{
			putchar('-');
			data=-data;
		}
		index=0;
		while(data)
		{
			result[index++]=data%r;
			data=data/r;
		}
		if(index == 0)printf("0");
		while(index > 0)
		{
			--index;
			if(result[index] < 10)
			{
				printf("%d",result[index]);
			}
			else
			{
				printf("%c",result[index]+55);
			}
		}
		printf("\n");
	}
	return 0;
}
