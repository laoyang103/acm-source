#include <stdio.h>
__int64 memory[64];
__int64 divide(int n)
{
	if(n<=1) return 1;
	else if(memory[n]==0)
	{
		memory[n]= divide(n-1)+divide(n-2);
	}
	return memory[n];
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%I64d\n",divide(n));
	}
	return 0;
}
/*fabinaci��������
f(n)=f(n-1)+fn(n-2).
f(n-1)��ʾ����һ���������ŷţ����ܷŷ���
f(n-2)��ʾ��ǰ�������Ӻ��ŷţ����ܷŷ���
*/
