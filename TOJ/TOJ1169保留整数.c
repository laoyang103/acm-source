#include <stdio.h>
#include <string.h>
char* Convert(char *destStr,char *srcStr)
{
	int i=0;
	int isLastNum=1;//��¼�ϴδ�����Ƿ��������ַ�
	char *p=srcStr;
	char c=*p;
	while(c != 0)
	{
		if((c >= 48) && (c <58) )//�������ַ�
		{
			destStr[i++]=c;
			isLastNum=1;
		}
		else//�ַ�
		{
			if(1 == isLastNum)
			{
				destStr[i++]='*';
				isLastNum=0;
			}
		}	
		++p;
		c=*p;
	}
	destStr[i]=0;
	return destStr;
}
int main()
{
	char str[81];
	char result[81];
	gets(str);
	puts(Convert(result,str));
	return 0;
}
/*
���յó�����*p�ķ����ٶȱȽ�������������ж�γ���*p��
�����ʹ��һ��������¼*p��ֵ����������һ�����ٶȡ�
*/
