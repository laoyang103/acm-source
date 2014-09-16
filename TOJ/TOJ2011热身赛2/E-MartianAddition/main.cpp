#include <cstdio>
#include <cstring>
using namespace std;
void strToInt(char *in,int *num)
{
	for(int i=strlen(in)-1;i>=0;--i)
	{
		if(in[i]>='0' && in[i]<='9')
		{
			num[i]=in[i]-'0';
		}
		else
		{
			num[i]=in[i]-'a'+10;
		}
	}
}

void sum(int *nu1,int *nu2,int len)
{
	for(int i=0;i<len;++i)
	{
		nu1[i]+=nu2[i];
		nu1[i+1]=nu2[i]/20;
		nu1[i] %= 20;
	}
}

int main()
{
    char input[128];
    int num1[128];
    int num2[128];
    while(gets(input) != NULL)
    {
    	memset(num1,0,sizeof(num1));
    	memset(num2,0,sizeof(num2));
    	strToInt(input,num1);
    	int length=strlen(input);
    	gets(input);
    	strToInt(input,num2);
    	if(length < strlen(input))
    	{
    		length=strlen(input);
    	}
    	sum(num1,num2,length);
    	int start=length;
    	if(num1[length] == 0)
    	{
    		--start;
    	}
    	for(int i=start;i>=0;--i)
    	{
    		if(num1[i]<10)
    		{
    			printf("%d",num1[i]);
    		}
    		else
    		{
    			printf("%c",num1[i]-10+'a');
    		}
    	}
    	printf("\n");
    }
    return 0;
}
