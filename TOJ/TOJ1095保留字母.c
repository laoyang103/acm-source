#include <stdio.h>
#include <string.h>
char str[81];
int main()
{
	int i,len;
	gets(str);
	len=strlen(str);
	for(i=0;i<len;++i)
	{
		if(str[i]<65 || str[i]>122 || (str[i]>90 && str[i]<97))
			continue;
		printf("%c",str[i]);
	}
	printf("\n");
	return 0;
}
/*
此题数据量较大，
当判断改为if((str[i]>=65 && str[i]<=90)) ||  (str[i]<=97 && str[i]>=122))
			printf("%c",str[i]);
时间都会变成15ms。
总结：尽可能早的介绍判断语句。
*/