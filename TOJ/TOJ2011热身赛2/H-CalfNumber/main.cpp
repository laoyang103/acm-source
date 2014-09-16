#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;
char rm[10][5]={"no","pa","re","ci","vo","mu","xa","ze","bi","so"};
int main()
{
	map<string,int> m;
	m["no"]=0;
	m["pa"]=1;
	m["re"]=2;
	m["ci"]=3;
	m["vo"]=4;
	m["mu"]=5;
	m["xa"]=6;
	m["ze"]=7;
	m["bi"]=8;
	m["so"]=9;
	char input[100];
	int n=6;
	long long sum=0;
	while(n--)
	{
		gets(input);
		long long num=0;
		for(int i=0;i<strlen(input);)
		{
			if(input[i]==' ')
			{
				++i;
			}
			else
			{
				string s(input+i,2);
				num=num*10+m[s];
				i+=2;
			}
		}
		sum+=num;
	}
	string r="";
	string t;
	while(sum != 0)
	{
		t=rm[sum%10];
		r=t+r;
		sum/=10;
	}
	printf("%s\n",r.c_str());
    return 0;
}
