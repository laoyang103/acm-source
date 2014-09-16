#include<iostream>
using namespace std;
char maze[20][20];
int mark[20][20];
int desti,destj;
int length,height;
bool DFS(int srci,int srcj,int t)
{
	if(t<0)
		return false;
	if(desti==srci && destj==srcj) 
		return true;
	if(mark[srci][srcj])
		return false;
	mark[srci][srcj]=1;
	--t;
	bool r=false;
	if(srci<height-1 && maze[srci+1][srcj]!='*')
		r=DFS(srci+1,srcj,t);
	if(!r && srci>0 && maze[srci-1][srcj]!='*')
		r=DFS(srci-1,srcj,t);
	if(!r && srcj<length-1 && maze[srci][srcj+1]!='*')
		r=DFS(srci,srcj+1,t);
	if(!r && srcj>0 && maze[srci][srcj-1]!='*')
		r=DFS(srci,srcj-1,t);
	return r;
}
int main()
{
	int i,j;
	int srci,srcj,day;
	while(1)
	{
		cin>>length>>height>>day;
		if(length+height+day==0)
			break;
		for(i=0;i<height;++i)
			for(j=0;j<length;++j)
			{
				cin>>maze[i][j];
				if(maze[i][j]=='S')
				{
					srci=i;
					srcj=j;
				}
				if(maze[i][j]=='P')
				{
					desti=i;
					destj=j;
				}
			}
		memset(mark,0,sizeof(mark));
		if(DFS(srci,srcj,day))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}