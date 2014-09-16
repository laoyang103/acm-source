#include <stdio.h>
#include <string.h>
int counter[256];
char str[100001];
int main()
{
	int i;
	while(gets(str)!=NULL)
	{
		memset(counter,0,sizeof(counter));
		for(i=strlen(str)-1;i>=0;--i)
		{
			if(str[i]>='a' && str[i]<='z')//一定要筛选，其中有的字符可能在0～256之外
			{
				++counter[str[i]];
			}
		}
		for(i='a';i<='z';++i)
		{
			printf("%c:%d\n",i,counter[i]);
		}
		printf("\n");
	}
	return 0;
}
