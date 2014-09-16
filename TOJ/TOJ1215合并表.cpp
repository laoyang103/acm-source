#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void Show(int data)
{
	cout<<" "<<data;
}
int main()
{
	list<int> lst1,lst2;
	int testCases;
	cin>>testCases;
	int n,data;
	while(testCases--)
	{
		cin>>n;
		while(n--)
		{
			cin>>data;
			lst1.push_back(data);
		}
		cin>>n;
		while(n--)
		{
			cin>>data;
			lst2.push_back(data);
		}
		lst1.merge(lst2);//按升序合并两个链表
		n=lst1.size();
		cout<<n;
		for_each(lst1.begin(),lst1.end(),Show);//遍历链表
		cout<<endl;
		lst1.clear();
		lst2.clear();
	}
	return 0;
}
