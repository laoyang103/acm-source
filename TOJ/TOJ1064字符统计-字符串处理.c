#include<stdio.h>
char input[100001];
int main()
{
	int i;
	int numberCounter,letterCounter;
	int othersCounter,spaceCounter;
	char ch;
	while(gets(input))
	{
		numberCounter=letterCounter=othersCounter=spaceCounter=0;
		i=0;
		while(input[i])
		{
			ch=input[i++];
			if((ch>64 && ch<91) ||(ch>96 && ch<123))++letterCounter;
			else if(ch>47 && ch<58)++numberCounter;
			else if(ch==32)++spaceCounter;
		}
		othersCounter=i-letterCounter-numberCounter-spaceCounter;
		printf("%d %d %d %d\n",letterCounter,numberCounter,spaceCounter,othersCounter);
	}
}
