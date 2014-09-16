#include <stdio.h>
#include <ctype.h>
#include <string.h>
char str[1024];
void parse(int i,int k)
{
	if(i<0)
	{
		for(int j=strlen(str)+1;j>0;--j)
		{
			str[j]=str[j-1];
		}
		if(k==1) str[0]='0';
		else if(k==2) str[0]='a';
		else if(k==3) str[0]='A';
		
		return ;
	}
	if(isdigit(str[i]))
	{
		if(++str[i]>'9')
		{
			str[i]='0';
			parse(i-1,1);
		}
	}
	else if(islower(str[i]))
	{
		if(++str[i]>'z')
		{
			str[i]='a';
			parse(i-1,2);
		}
	}
	else if(isupper(str[i]))
	{
		if(++str[i]>'Z')
		{
			str[i]='A';
			parse(i-1,3);
		}
	}
	else 
	{
		parse(i-1,k);
	}
}
int nonalphanumerics()
{
	for(int i=strlen(str)-1;i>=0;--i)
	{
		if(isdigit(str[i])||islower(str[i])||isupper(str[i]))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",str,&n);
		for(int i=0;i<n;++i)
		{
			int len=strlen(str)-1;
			if(nonalphanumerics())
			{
				++str[len];
			}
			else parse(len,0);
			puts(str);
		}
		printf("\n");
	}
	return 0;
}
