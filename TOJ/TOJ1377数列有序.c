#include <stdio.h>
int array[101];
int bi_search(int left,int right,int data)//�۰����
{
	int m=(left+right)/2;
	if(left >= right) return left;
	if(data == array[m]) return m;
	if(data < array[m]) return bi_search(left,m-1,data);
	return bi_search(m+1,right,data);
}
int main()
{
	int n,m;
	int pos,i;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n+m == 0)break;
		for(i=0;i<n;++i)scanf("%d",array+i);
		pos = bi_search(0,n-1,m);
		if(m > array[pos])++pos;//Ԥ��Ҫ���������������ĩβ
		for(i=n;i>pos;--i)array[i]=array[i-1];//����ƶ�
		array[pos]=m;
		for(i=0;i<n;++i)
		{
			printf("%d ",array[i]);
		}
		printf("%d\n",array[n]);
	}
	return 0;
}
