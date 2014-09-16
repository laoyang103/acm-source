#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(int data)
{
	cout<<" "<<data;
}
int main()
{
	vector<int> vec;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int data;
		while(n--)
		{
			cin>>data;
			vec.push_back(data);
		}
		cin>>data;
		vec.erase(find(vec.begin(),vec.end(),data));
		vector<int>::iterator it=vec.begin();
		cout<<*it;
		++it;
		for_each(it,vec.end(),show);
		cout<<endl;
		vec.clear();
	}
	return 0;
}
