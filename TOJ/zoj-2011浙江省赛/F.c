#include <stdio.h>
#include <string.h>
char array[100][21];
int main()
{
	int t,n,i;
	int pos;
	char front[21];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,front);
		for(i=0;i<n;++i)
		{
			scanf("%s",array[i]);
			if(strcmp(front,array[i])==0)
			{
				pos=i;
			}
		}
		printf("%s\n",array[(pos+n/2)%n]);
	}
	return 0;
}
