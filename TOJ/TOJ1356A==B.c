#include <stdio.h>
#include <string.h>
char a[1024],b[1024];

//ȥ��ʵ��β��0
int formatTail(char *pStr)
{
	int len;
	if(strchr(pStr,'.') == NULL)//����ʵ��
	{
		return 0;
	}
	len=strlen(pStr)-1;
	//ȥ��β��0
	while(pStr[len]=='0')
	{
		--len;
	}
	//ȥ��β����С����
	if(pStr[len] == '.')
	{
		pStr[len]='\0';
	}
	else pStr[len+1]='\0';
	return 1;
}
//��ʽ���ײ�
char* formatFront(char *pStr)
{
	char *p=pStr;
	if(*p == '-')//����
	{
		//�ж��Ƿ���0
		if(isEqual(p+1,"0")==1)
		{
			p[0]='\0';
		}
	}
	else
	{	//ȥ��ǰ��0
		while(*p == '0')++p;
	}
	return p;
}
int isEqual(char *pa,char *pb)
{
	formatTail(pa);
	formatTail(pb);
	pa=formatFront(pa);
	pb=formatFront(pb);
	
//	printf("%s %s\n",pa,pb);���Ը�ʽ����Ľ��
	
	while(*pa!=0 && *pb!=0)
	{
		if(*pa != *pb)
		{
			return 0;
		}
		++pa;
		++pb;
	}
	if(*pa!=0 || *pb!=0)return 0;
	return 1;
}
int main()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		if(isEqual(a,b))puts("YES");
		else puts("NO");
	}
	return 0;
}
/*��������
1.0 1.00
1.0 1.100
1.1 1.100
0 0.0
-0 0
-0.0 0
-0 0.0
-0.123 0.123
012 12
123 123456
*/
