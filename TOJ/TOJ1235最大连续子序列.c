#include<stdio.h>
int array[10001];//��������
int memory[10001];
int main()
{
	int n,i;
	int start,end,max;
	memory[0]=0;
	while(scanf("%d",&n),n)
	{
		max=-1000000;
		for(i=1;i<=n;++i)
		{
			scanf("%d",array+i);
			if(memory[i-1]>=0)
			{
				memory[i]=memory[i-1]+array[i];
			}
			else
			{
				memory[i]=array[i];
			}
			if(max < memory[i])//�ҳ�����
			{
				max=memory[i];
				end=i;
			}
		}
		for(i=end;i>0;--i)
		{
			if(memory[i]<0)
			{
				break;
			}
		}
		start=i+1;
		if(start > end)//����ȫΪ���������ݣ�����ļ�������start>end
		{
			start=1;
			end=n;
			max=0;
		}
		printf("%d %d %d\n",max,array[start],array[end]);
	}
	return 0;
}
/*
������1202����
*/
