#include<stdio.h>
int main()
{
	int input,i;
	scanf("%d",&input);
	for(i=1;i<=input;++i)
	{
		if(i%3==0 && i%5==0)printf("DeadMan\n");
		else if(i%3==0)printf("Dead\n");
		else if(i%5==0)printf("Man\n");
		else
		{
			if(i!=input)printf("%d ",i);
			else printf("%d\n",i);
		}
	}
	return 0;
}
