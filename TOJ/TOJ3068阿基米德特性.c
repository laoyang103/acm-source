#include <stdio.h>
int GetAJMD(int a,int b)//��ð����׵���
{
	int m=b/a;
	if(a*m <= b)
	{
		m+=1;
	}
	return m;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",GetAJMD(a,b));
	return 0;
}
