#include <stdio.h>
#include <string.h>
char map[128];//将合法字符进行标记
char password[51];//密码
void initMap()
{
	int i;
	char character[]="~!@#$%^";
	for(i='A';i<='Z';++i)
	{
		map[i]=1;//大写字母标记为1
		map[i+32]=2;//小写字母标记为2
	}
	for(i='0';i<='9';++i)
	{
		map[i]=3;//数字字符标记为3
	}
	for(i=0;i<=7;++i)
	{
		map[character[i]]=4;//特殊字符标记为4
	}
}
int isSafePass()
{
	int mark[5]={0};//用来记录4种字符的数量
	char ch;
	int i;
	int counter;
	int len=strlen(password);
	if(len<8 || len>16)//超过限定长度
	{
		return 0;
	}
	for(i=0;i<len;++i)
	{
		ch=password[i];
		++mark[map[ch]];
	}
	counter=0;
	for(i=1;i<=4;++i)
	{
		if(mark[i]!=0)
		{
			++counter;
		}
	}
	if(counter>=3)return 1;//含有3种以上字符
	else return 0;
}
int main()
{
	int t;
	initMap();
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(password);
		if(isSafePass()==1)
		{
			puts("YES");
		}
		else puts("NO");
	}
	return 0;
}
