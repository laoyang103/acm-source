#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
void show(int i)
{
	cout<<" "<<i;
}
int main()
{
	multiset<int> my_set;
	int n,m;
	while(1)
	{
		cin>>n>>m;
		if(n+m == 0)break;
		int input;
		for(int i=0;i<n;++i)
		{
			cin>>input;
			my_set.insert(input);
		}
		my_set.insert(m);
		multiset<int>::iterator it=my_set.begin();
		cout<<*it;
		for_each(++it,my_set.end(),show);
		cout<<endl;
		my_set.clear();
	}
	return 0;
}
