#include<string.h>
#include<stdio.h>
//��ϣ����a~zӳ��ɶ�Ӧ�����֡�
char map[]="22233344455566677778889999";
char a[101],b[101];//a���������ַ�����b��������ַ���
char code(char c)//����
{
	if(c>='a' && c<='z')
	{	
		return map[c-'a'];
	}
	else if(c>='A' && c<'Z')
	{
		return c+32+1;//'a'='A'+32
	}
	else if(c=='Z')
		return 'a';
	return c;
}
int main()
{	 
	int m,n;
	while(scanf("%s",a)==1)
	{		
		m=strlen(a);
		for(n=0;n<m;n++)
			b[n]=code(a[n]);
		b[n]=0;
		printf("%s\n",b);
	};	
	return 0;
}