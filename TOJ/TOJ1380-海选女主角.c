#include <stdio.h>
int abs(int a)
{
	if(a<0)a=-a;
	return a;
}
int main()
{
	int m,n;
	int i,j;
	int temp;
	int maxScore,mi,mj;
	int min=-2147483648;//ע������迼���������������,��ȻҲ����ʹ��64λ��������
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		maxScore=0;
		mi=1;
		mj=1;
		for(i=1;i<=m;++i)
		{
			for(j=1;j<=n;++j)
			{
				scanf("%d",&temp);
				if(maxScore!=min && (abs(maxScore) < abs(temp) || temp==min))
				{
					maxScore=temp;
					mi=i;
					mj=j;
				}
			}
		}
		printf("%d %d %d\n",mi,mj,maxScore);
	}
	return 0;
}
