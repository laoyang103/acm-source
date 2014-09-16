#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int main()
{
	int n;
	char str[100];
	int mark[26];
	set<char> salon;
	while(scanf("%d",&n),n)
	{
		scanf("%s",str);
		int remain=n;
		int leave=0;
		salon.clear();
		memset(mark,0,sizeof(mark));
		for(int i=0;i<strlen(str);++i)
		{
			if(salon.find(str[i]) == salon.end())//没在
			{
				salon.insert(str[i]);
				if(remain > 0)
				{
					mark[str[i]-'A']=1;
					--remain;
				}
				else
				{
					++leave;
				}
			}
			else//第二次出现则离开
			{
				salon.erase(str[i]);
				if(mark[str[i]-'A'] != 0)
				{
					++remain;
				}
			}
		}
		if(leave == 0)
		{
			puts("All customers tanned successfully.");
		}
		else
		{
			printf("%d customer(s) walked away.\n",leave);
		}
	}
	return 0;
}
