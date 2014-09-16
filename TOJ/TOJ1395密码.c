#include <stdio.h>
#include <string.h>
char map[128];//���Ϸ��ַ����б��
char password[51];//����
void initMap()
{
	int i;
	char character[]="~!@#$%^";
	for(i='A';i<='Z';++i)
	{
		map[i]=1;//��д��ĸ���Ϊ1
		map[i+32]=2;//Сд��ĸ���Ϊ2
	}
	for(i='0';i<='9';++i)
	{
		map[i]=3;//�����ַ����Ϊ3
	}
	for(i=0;i<=7;++i)
	{
		map[character[i]]=4;//�����ַ����Ϊ4
	}
}
int isSafePass()
{
	int mark[5]={0};//������¼4���ַ�������
	char ch;
	int i;
	int counter;
	int len=strlen(password);
	if(len<8 || len>16)//�����޶�����
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
	if(counter>=3)return 1;//����3�������ַ�
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
