#include<cstdio>
#include<cstring>
char uperList[27]	="ECFAJKLBDGHIVWZYMNOPQRSTUX";
char lowerList[27]	="erwqtyghbnuiopsjkdlfazxcvm";
int main()
{
	int len,i;
	char input[1024];
	while(true)
	{
		gets(input);
		len=strlen(input);
		for(i=0;i<len;++i)
		{
			if(input[i]=='#')
				break;
			if(input[i]>='a' && input[i]<='z')
				printf("%c",lowerList[input[i]-'a']);
			else if(input[i]>='A' && input[i]<='Z')
				printf("%c",uperList[input[i]-'A']);
			else
				printf("%c",input[i]);
		}
		if(i>=len)
			printf("\n");
		else
			break;
	}
	return 0;
}