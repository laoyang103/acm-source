#include<cstdio>
#include<cstring>
char uperList[27]	="ECFAJKLBDGHIVWZYMNOPQRSTUX";
char lowerList[27]	="erwqtyghbnuiopsjkdlfazxcvm";
int main()
{
	int ch;
	while(true)
	{
		ch=getchar();
		if(ch=='#')
			break;
		if(ch>='a' && ch<='z')
			printf("%c",lowerList[ch-'a']);
		else if(ch>='A' && ch<='Z')
			printf("%c",uperList[ch-'A']);
		else
			printf("%c",ch);
	}
	return 0;
}