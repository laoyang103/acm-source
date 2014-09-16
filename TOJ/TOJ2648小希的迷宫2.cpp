#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

int parent[100001];//�������ĸ��ڵ�

int getRoot(int v)//��ý��ĸ����
{
	while(v != parent[v])
	{
		v=parent[v];
	}
	return v;
}
void resetParent()//����parent����
{
	int i;
	for(i=0;i<100001;++i)
	{
		parent[i]=i;
	}
}
int main()
{
	int a,b;
	bool result=true;
	list<int> lst;//��¼����������Щ���
	resetParent();
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(-1 == a && -1 == b)
		{
			break;
		}
		else if(0==a && 0==b)
		{
			if(result)//�ж��Ƿ���ͨ
			{
				list<int>::const_iterator it,itEnd;
				it=lst.begin();
				itEnd=lst.end();
				int t=getRoot(*it);
				for (++it; it!=itEnd; ++it)
				{
					if (getRoot(*it) != t)//��������������㣬˵������ͨ
					{
						result=false;
						break;
					}
				}
			}
			if(result)
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
			//��������
			result=true;
			resetParent();
			lst.clear();
		}
		else if(1 == result)
		{
			lst.push_back(a);
			lst.push_back(b);

			parent[a]=getRoot(a);
			parent[b]=getRoot(b);
			if(parent[a]==parent[b])
			{
				result=false;
			}
			else
			{
				parent[parent[b]]=parent[a];
			}
		}
	}
	return 0;
}
