#include <cstdio>
int main()
{
	int t;
	__int64 a,b,c,d,v;
	scanf("%d",&t);
	while(t--)
	{
		v=0;
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
		__int64 m,t;
		/*��abc����С�������򣬴����Ŀ�ʼ��*/
		if(a>b){m=a;a=b;b=m;}
		if(a>c){m=a;a=c;c=m;}
		if(b>c){m=b;b=c;c=m;}
		
		m=c-b;//�ȳ��Է�c��b��������ǲ���
		if(m >= d)//��c�㹻��
		{
			c-=d;
		}
		else//������
		{
			m=c-a+b-a;//��b��c��a��������ǲ���
			if(m >= d)//��b��c���㹻��
			{
				t=m-d;
				b=a+t/2;
				t-=t/2;
				c=a+t;
			}
			else//�����֣���Ҫ��a��b��c
			{
				t=d-m;//����m��������t��
				//��t�ֳ�3�ݣ���a�Ļ����϶���ȥ��3�ȷ�
				long long average=a;
				a=average-t/3;
				t-=t/3;
				b=average-t/2;
				t-=t/2;
				c=average-t;
			}
		}
		printf("%I64d\n",a*b*c);
	}
	return 0;
}
