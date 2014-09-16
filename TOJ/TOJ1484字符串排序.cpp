#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	multiset<string> my_set;
	string str;
	for(int i=0;i<3;++i)
	{
		cin>>str;
		my_set.insert(str);
	}
	multiset<string>::iterator it,it_end;
	it=my_set.begin();
	cout<<*it;
	it_end=my_set.end();
	++it;
	for(;it!=it_end;++it)
	{
		cout<<" "<<*it;
	}
	return 0;
}
