#include <stdio.h>
int main()
{
	int t,n,i;
	double h,dis;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%d",&h,&n);
		dis=h;//��¼�ܾ���
		for(i=1;i<n;++i)
		{
			h=h/2.0;
			dis+=h*2;//���������󣬻�Ҫ���½�����*2
		}
		printf("%.2lf %.2lf\n",dis,h/2.0);
	}
	return 0;
}
