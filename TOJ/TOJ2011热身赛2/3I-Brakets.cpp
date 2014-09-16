#include <cstdio>
#include <cstring>
using namespace std;

int memory[101][101];
char input[101];

int max(int a,int b)
{
	return a>b?a:b;
}

int brackets(int i,int j)
{
	if(i >= j) return 0;
	if(memory[i][j] == -1)
	{
		int temp=0;
		if((input[i]=='(' && input[j]==')') ||(input[i]=='[' && input[j]==']'))
		{
			memory[i][j]=brackets(i+1,j-1)+2;
		}
		else
		{
			memory[i][j]=max(brackets(i,j-1),brackets(i+1,j));
		}
		for(int k=i+1;k<j;++k)
		{
			temp=brackets(i,k)+brackets(k+1,j);
			if(memory[i][j] < temp)
			{
				memory[i][j]=temp;
			}
		}
	}
	return memory[i][j];
}
int main()
{
	while(1)
	{
		gets(input);
		if(strcmp(input,"end")==0)
		{
			break;
		}
		memset(memory,-1,sizeof(memory));
		printf("%d\n",brackets(0,strlen(input)-1));
	}
	return 0;
}
