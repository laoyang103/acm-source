//��ͨ��
#include <cstdio>
#include <map>
#include <set>
using namespace std;

/*
map���ص㣺���������ظ���key���ʿ���������¼������Ҳ�����ж�
һ������Ƿ����������ڵ�
*/
map<int,int> tree;//������

//set���ص㣺���������ظ��ĵ���ڣ��ʿ���ʹ��������¼����Щ��㡣
set<int> node;//������

int main()
{
	int a,b;
	int root,r;
	int testCase=1;
	bool bTree=true;
	while(1)
	{
		scanf("%d%d",&a,&b);
		if(a < 0 && b < 0 )
		{
			break;
		}
		else if(0 == a && 0 == b)
		{
			if(bTree)//�ж��Ƿ���ɭ��
			{
				//node.size()!=0�ж��Ƿ��ǿ���
				//node.size()-1 != tree.size()������ܱȱ�����1��
				if(node.size()!=0 && node.size()-1 != tree.size() )
				{
					bTree=false;
				}
			}
			if(bTree)
			{
				printf("Case %d is a tree.\n",testCase);
			}
			else
			{
				printf("Case %d is not a tree.\n",testCase);
			}
			bTree=true;
			tree.clear();
			node.clear();
			++testCase;
		}
		else
		{ 
			if(bTree)
			{
				if(tree[b] == 0)
				{
					tree[b]=a;//��¼���ĸ��ڵ�
					node.insert(a);//��¼���
					node.insert(b);
				}
				else//һ�������������ڵ㣬������
				{
					bTree=false;
				}
			}
		}
	}
	return 0;
}
