#include <stdio.h>
int main()
{
	int i=0;//��¼���ʸ���
	char input[256];
	while(scanf("%s",input)==1)
	{
		++i;
	}
	printf("%d\n",i);
	return 0;
}
