#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string str;
	str.reserve(32);
	while(t--)
	{
		cin>>str;
		bool bHui=true;
		int i=str.size()-1;
		int j=0;
		for(;i>j;--i,++j)
		{
			if(str.at(i)!= str.at(j))
			{
				bHui=false;
				break;
			}
		}
		if(bHui)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
