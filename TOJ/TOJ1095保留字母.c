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
�����������ϴ�
���жϸ�Ϊif((str[i]>=65 && str[i]<=90)) ||  (str[i]<=97 && str[i]>=122))
			printf("%c",str[i]);
ʱ�䶼����15ms��
�ܽ᣺��������Ľ����ж���䡣
*/