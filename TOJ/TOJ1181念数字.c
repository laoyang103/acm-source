#include <stdio.h>
char map[11][10]={"LING","YI","ER","SAN","SI","WU","LIU","QI","BA","JIU","SHI"};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0 || n>=100)
		{
			printf("CUO LE");
		}
		else if(n <= 10)
		{
			printf("%s",map[n]);
		}
		else if(n < 20)
		{
			printf("SHI %s",map[n%10]);
		}
		else
		{
			printf("%s SHI",map[n/10]);
			n%=10;
			if(n !=0)
			{
				printf(" %s",map[n]);
			}
		}
		printf("\n");
	}
	return 0;
}
