#include <stdio.h>
char subStr[100001];
char srcStr[100001];
int isSub(char *psub,char *psrc)//判断是否可在psrc中找到字串psub
{
	while((*psub !=0) && (*psrc != 0))
	{
		if(*psub == *psrc)
		{
			++psub;
		}
		++psrc;
	}
	if(*psub == 0)return 1;
	else return 0;
}
int main()
{
	while(scanf("%s%s",subStr,srcStr)!=EOF)
	{
		if(isSub(subStr,srcStr)==1)
		{
			puts("Yes");
		}
		else puts("No");
	}
	return 0;
}
