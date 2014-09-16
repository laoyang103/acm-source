#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	typedef vector<int>::iterator ptrVector;
	vector<int> vec;
	vec.push_back(0);
	string command;//ÃüÁî
	while(1)
	{
		cin>>command;
		if("exit" == command)
		{
			break;
		}
		else if("clear" == command)
		{
			vec.clear();
			vec.push_back(0);
		}
		else if("insert" == command)
		{
			int n,i;
			int pos,data;
			cin>>n;
			ptrVector it,itEnd;
			while(n--)
			{
				cin>>pos>>data;
				i=0;
				itEnd=vec.end();
				for(it=vec.begin();it!=itEnd;++it)
				{
					if(i == pos)
					{
						break;
					}
					++i;
				}
				vec.insert(it,data);
			}
		}
		else if("delete" == command)
		{
			int i;
			int pos;
			cin>>pos;
			ptrVector it,itEnd=vec.end();
			i=0;
			for(it=vec.begin();it!=itEnd;++it)
			{
				if(i == pos)
				{
					break;
				}
				++i;
			}
			cout<<(*it)<<endl;
			vec.erase(it);
		}
		else if("getelem" == command)
		{
			int pos;
			cin>>pos;
			cout<<vec[pos]<<endl;
		}
		else
		{
			
		}
	}
	return 0;
}
