#include <cstdio>
#include <cstring>
char str[1001];//���ܵ��ַ���
int length;//�ַ�������
void ToLeft(int width)//������ת
{
    int i;
	char temp=str[width-1];//�����һ����width������Ԫ�أ�
    //ע�������±��0��ʼ������Ŀ�ı���������ڴ�1��ʼ���Ե� 
	for(i=width-1;i+width<length;i+=width)//ÿ������width���±� 
		str[i]=str[i+width]; //�������������� 
	str[i]=temp;//������ߵ��ַ��ŵ����ұ� 
}
void ToRight(int width)//������ת
{
    int i;
	int t=length/width*width;
	char temp=str[t-1];
	for(i=t-1;i-width>=0;i-=width)
		str[i]=str[i-width];
	str[i]=temp;
}
int main()
{
	while(gets(str))
	{
		length=strlen(str);
		for(int i=length;i>0;--i)
			if(i%2!=0)//��������������ʱ�룩
				ToLeft(i);
			else
				ToRight(i);
		printf("%s\n",str);
	}
	return 0;
}
