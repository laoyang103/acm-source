#include<stdio.h>
int main()
{
	int n;//ͷ
	int m;//��
	int x;//������
	int y;//������
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n+m==0)
			break;
		/*��ע��Լ������,�ŵ�����Ϊż����
		�ҽŵ��������ܴ���ͷ��4����
		���ҽŵ�������������ͷ��2����*/
		if((m%2!=0)||(m<2*n)||(m>4*n))
			printf("Error\n");
		else
		{
			y=(m-n*2)/2;
			x=n-y;
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}