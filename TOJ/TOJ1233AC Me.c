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
			if(str[i]>='a' && str[i]<='z')//һ��Ҫɸѡ�������е��ַ�������0��256֮��
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
