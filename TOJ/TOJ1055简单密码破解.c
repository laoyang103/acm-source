#include <stdio.h>
char map1[]="22233344455566677778889999";//Сд��ĸӳ���
char map2[]="bcdefghijklmnopqrstuvwxyza";//��д��ĸӳ���
char input[101];
int main()
{
	char *p=NULL;
	char ch;
	while(gets(input) != NULL)
	{
		p=input;
		while(0 != *p)
		{
			ch = *p;
			if(ch >= 'a' && ch <='z')
			{
				*p=map1[ch-'a'];
			}
			else if(ch >= 'A' && ch <= 'Z')
			{
				*p=map2[ch-'A'];
			}
			++p;
		}
		puts(input);
	}
	return 0;
}
