#include <iostream>
#include <cstring>
using namespace std;
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
	if(i > N)//����N��
	{
		return 0;
	}
	if(0 == memory[i][remainC])
	{
		/*
		* dis 	��ʾ�ڹ���糵�����ߵľ���
		* rc 	��ʾ����ö�·�󣬵糵�������ߵľ���
		* dis/V1 	��ʾ��糵���ߵ�ʱ��
		* (array[i]-dis)/V2 	��ʾ��ǳ����ߵ�ʱ��
		*/
		//���
		double dis=C>array[i] ? array[i] : C;//��糵���ߵľ���
		int rc=C>array[i] ? C-array[i] : 0;//�糵ʣ����߾���
		double charge=DP(i+1,rc)+T+dis/V1+(array[i]-dis)/V2;
		
		//�����
		dis=remainC>array[i] ? array[i] : remainC;//��糵���ߵľ���
		rc=remainC>array[i] ? remainC-array[i] : 0;//�糵ʣ����߾���
		double notCharge=DP(i+1,rc)+dis/V1+(array[i]-dis)/V2;
		
		memory[i][remainC]=charge<notCharge ? charge : notCharge;
	}
	return memory[i][remainC];
}
int main()
{
	while(cin>>L)
	{
		cin>>N>>C>>T;
		cin>>VR>>V1>>V2;
		for(int i=0;i<N;++i)
		{
			cin>>array[i];
		}
		array[N]=L;//��ע��N����վ��·�ֳ�N+1��
		for(int i=N;i>=0;--i)
		{//����ÿ������վ֮��ľ���
			array[i]-=array[i-1];
		}
		memset(memory,0,sizeof(memory));
		if((double)L/VR < DP(0,C))
		{
			cout<<"Good job,rabbit!"<<endl;
		}
		else
		{
			cout<<"What a pity rabbit!"<<endl;
		}
	}
	return 0;
}
