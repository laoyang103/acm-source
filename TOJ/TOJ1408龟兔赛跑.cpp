#include <iostream>
#include <cstring>
using namespace std;
int array[101];//距离数组，为每两站之间的距离
double memory[101][1000];//记忆数组
int L;//总距离
int N,C,T;//电站个数
int VR,V1,V2;//兔、电车、龟速度
/*动态规划
* i:第i段路程
* remainC：当前电车可走距离
*/
double DP(int i,int remainC)
{
	if(i > N)//超过N段
	{
		return 0;
	}
	if(0 == memory[i][remainC])
	{
		/*
		* dis 	表示乌龟骑电车可以走的距离
		* rc 	表示走完该段路后，电车还可以走的距离
		* dis/V1 	表示骑电车所走的时间
		* (array[i]-dis)/V2 	表示龟登车所走的时间
		*/
		//充电
		double dis=C>array[i] ? array[i] : C;//骑电车可走的距离
		int rc=C>array[i] ? C-array[i] : 0;//电车剩余可走距离
		double charge=DP(i+1,rc)+T+dis/V1+(array[i]-dis)/V2;
		
		//不充电
		dis=remainC>array[i] ? array[i] : remainC;//骑电车可走的距离
		rc=remainC>array[i] ? remainC-array[i] : 0;//电车剩余可走距离
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
		array[N]=L;//需注意N个电站将路分成N+1段
		for(int i=N;i>=0;--i)
		{//计算每相邻两站之间的距离
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
