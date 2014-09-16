#include<iostream>
#include<string.h>
using namespace std;
int a[101][101];

int main()
{
	char str[101];
	int i,j,k,l;
	while(gets(str))
	{
		if (strcmp(str,"end")==0)break;
		l=strlen(str);
		memset(a,0,sizeof(a));
		for (i=1;i<=l;i++)
		{
			for (j=0;j+i<l;j++)
			{
				
				if (str[j]=='(' && str[j+i]==')' ||str[j]=='[' && str[j+i]==']'||str[j]=='{' && str[j+i]=='}')
				{
					a[j][j+i]=a[j+1][j+i-1]+1;
				}
				else if (a[j+1][j+i]>a[j][j+i-1])
				{
					a[j][j+i]=a[j+1][j+i];
				}
				else
				{
					a[j][j+i]=a[j][j+i-1];
				}
				
				for (k=j+1;k<j+i;k++)
				{
					if (a[j][k]+a[k+1][j+i]>a[j][j+i])
						a[j][j+i]=a[j][k]+a[k+1][j+i];
				}	
			}
		}
		cout<<2*a[0][l-1]<<endl;
	}
	return 0;
}

