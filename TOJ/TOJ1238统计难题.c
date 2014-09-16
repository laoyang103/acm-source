#include <stdio.h>
char words[10000][12];
int index=0;
int counter(char *str)
{
	int c=0;
	int i;
	int j;
	for(i=0;i<index;++i)
	{
		j=0;
		while(words[i][j]==str[j])
		{
			++j;
			if(str[j]==0)
			{
				++c;
				break;
			}
			else if(words[i][j]==0)
			{
				break;
			}
		}
	}
	return c;
}
int main()
{
	char str[128];
	while(1)
	{
		gets(words[index]);
		if(words[index][0]==0)break;
		++index;
	}
	while(gets(str) != NULL)
	{
		printf("%d\n",counter(str));
	}
	return 0;
}
