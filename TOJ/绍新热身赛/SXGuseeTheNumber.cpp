#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int array[100][100];
char operation[101];
int colum[101];
int n,m;
void Transform()
{
	int temp;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			temp=array[i][j];
			array[i][j]=array[j][i];
			array[j][i]=temp;
		}
}
void Rotate()
{
	int temp[100][100];
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			temp[j][n-i-1]=array[i][j];
		}
	}
	memcpy(array,temp,sizeof(array));
}
int main()
{
	int testCase;
	int result;
	set<int> open;
	set<int> close;
	scanf("%d",&testCase);
	int i,j;
	while(testCase--)
	{
		open.clear();
		close.clear();
		scanf("%d%d",&n,&m);
		for(i=0;i<n;++i)
			for(j=0;j<n;++j)
				scanf("%d",&array[i][j]);
		scanf("%s",operation);
		for(i=0;i<m+1;++i)
			scanf("%d",colum+i);
		for(i=0;i<n;++i)
			open.insert(array[i][colum[0]-1]);
		for(i=0;i<m;++i)
		{
			if(operation[i]=='r')
				Rotate();
			else
				Transform();
			set<int>::iterator it,itEnd;
			itEnd=open.end();
			for(j=0;j<n;++j)
			{
				it=open.find(array[j][colum[i+1]-1]);
				if(it!=itEnd)
				{
					close.insert(array[j][colum[i+1]-1]);
				}
			}
			open.swap(close);
			close.clear();
		}
		result=*open.begin();
		printf("%d\n",result);
	}
	return 0;
}
