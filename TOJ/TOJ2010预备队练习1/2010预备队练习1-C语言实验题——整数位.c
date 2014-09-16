#include<stdio.h>
int main()
{
	int input;
	int length,i;
	int array[6];
	scanf("%d",&input);
	length=0;
	while(input!=0)
	{
		array[length++]=input%10;
		input/=10;
	}
	if(length==0)
	{
		length=1;
		array[0]=0;
	}
	printf("%d\n",length);
	for(i=length-1;i>0;--i)
		printf("%d ",array[i]);
	printf("%d\n",array[0]);
	for(i=0;i<length-1;++i)
		printf("%d ",array[i]);
	printf("%d\n",array[i]);
	return 0;
}
