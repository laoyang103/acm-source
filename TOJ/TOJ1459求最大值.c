#include <stdio.h>
int main()
{
	int n,max,input;
	scanf("%d",&n);
	scanf("%d",&max);
	while(--n)
	{
		scanf("%d",&input);
		if(max<input)max=input;
	}
	printf("%d\n",max);
	return 0;
}
