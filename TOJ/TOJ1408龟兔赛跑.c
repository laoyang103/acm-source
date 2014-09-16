#include <stdio.h>
#include <string.h>
int array[101];//�������飬Ϊÿ��վ֮��ľ���
double memory[101][1000];//��������
int L;//�ܾ���
int N,C,T;//��վ����
int VR,V1,V2;//�á��糵�����ٶ�

/*��̬�滮
* i:��i��·��
* remainC����ǰ�糵���߾���
*/
double DP(int i,int remainC)
{
	double dis;//��ʾ�ڹ���糵�����ߵľ���
	int rc;//��ʾ����ö�·�󣬵糵�������ߵľ���
	double charge;//�������ʱ��
	double notCharge;//���������ʱ��
	if(i > N)//����N��
	{
		return 0;
	}
	if(0 == memory[i][remainC])
	{
		/*
		* dis/V1 	��ʾ��糵���ߵ�ʱ��
		* (array[i]-dis)/V2 	��ʾ��ǳ����ߵ�ʱ��
		*/
		//���
		dis=C>array[i] ? array[i] : C;//��糵���ߵľ���
		rc=C>array[i] ? C-array[i] : 0;//�糵ʣ����߾���
		charge=DP(i+1,rc)+T+dis/V1+(array[i]-dis)/V2;
		
		//�����
		dis=remainC>array[i] ? array[i] : remainC;//��糵���ߵľ���
		rc=remainC>array[i] ? remainC-array[i] : 0;//�糵ʣ����߾���
		notCharge=DP(i+1,rc)+dis/V1+(array[i]-dis)/V2;
		
		memory[i][remainC]=charge<notCharge ? charge : notCharge;
	}
	return memory[i][remainC];
}
int main()
{
	int i;
	while(scanf("%d",&L)==1)
	{
		scanf("%d%d%d",&N,&C,&T);
		scanf("%d%d%d",&VR,&V1,&V2);
		for(i=0;i<N;++i)
		{
			scanf("%d",array+i);
		}
		array[N]=L;//��ע��N����վ��·�ֳ�N+1��
		for(i=N;i>=0;--i)
		{//����ÿ������վ֮��ľ���
			array[i]-=array[i-1];
		}
		memset(memory,0,sizeof(memory));
		if((double)L/VR < DP(0,C))
		{
			puts("Good job,rabbit!");
		}
		else
		{
			puts("What a pity rabbit!");
		}
	}
	return 0;
}
