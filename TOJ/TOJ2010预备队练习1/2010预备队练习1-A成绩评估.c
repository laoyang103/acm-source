#include<stdio.h>
int main()
{
	int input;
	while(scanf("%d",&input)!=EOF)
	{
		if(input<0)printf("Score is error!\n");
		else if(input<60)printf("E\n");
		else if(input<70)printf("D\n");
		else if(input<80)printf("C\n");
		else if(input<90)printf("B\n");
		else if(input<=100)printf("A\n");
		else printf("Score is error!\n");
	}
	return 0;
}
