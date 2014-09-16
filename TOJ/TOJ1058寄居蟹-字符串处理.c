#include<stdio.h>
#include<string.h>
char hi[100001];
char ji[100001];

int main()
{
	int lenH,lenJ;
	int i,j;
	int yes;
	while(1)
	{
		scanf("%s%s",hi,ji);
		lenH=strlen(hi);
		lenJ=strlen(ji);
		if(hi[0]=='0' && ji[0]=='0')
			break;
		yes=1;
		if(lenH<lenJ)
			yes=0;
		i=j=0;
		while(yes)
		{//拿寄居蟹在海葵中查找
			if(ji[j]+hi[i]==155)
			{
				++i;
				++j;
			}
			else
			{
				++i;
			}
			if(i>=lenH)
				yes=0;
			if(j>=lenJ)
			{
				yes=1;
				break;
			}
		}
		if(yes)
			printf("Yes\n");
		else printf("No\n");
	}
}