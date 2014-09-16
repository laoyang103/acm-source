#include <cstdio>
#include <cstring>
using namespace std;
char map[8][4]={"TTT", "TTH","THT", "THH", "HTT", "HTH", "HHT", "HHH"};
int counter[8];
void match(char str[])
{
	for(int i=0;i<8;++i)
	{
		if(strncmp(map[i],str,3)==0)
		{
			++counter[i];
			break;
		}
	}
}
int main()
{
	int t;
	int n;
	char input[41];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,input);
		memset(counter,0,sizeof(counter));
		for(int i=0;i<38;++i)
		{
			match(input+i);
		}
		printf("%d",n);
		for(int i=0;i<8;++i)
		{
			printf(" %d",counter[i]);
		}
		printf("\n");
	}
	return 0;
}
