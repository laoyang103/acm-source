#include <iostream>
#include <set>
using namespace std;
int main()
{
	multiset<int> my_set;//输入数据集合
	int t;//测试数据组数
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;//数据个数
		int data;
		while(n--)
		{
			cin>>data;
			my_set.insert(data);
		}
		multiset<int>::iterator it,it_end;
		it=my_set.begin();
		it_end=my_set.end();
		cout<<*it;
		++it;
		while(it!=it_end)
		{
			cout<<" "<<*it;
			++it;
		}
		cout<<endl;
		my_set.clear();
	}
	return 0;
}
