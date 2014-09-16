#include <iostream>
#include <string>
using namespace std;

string sort(string &s)
{
	int iz=0,io=0,ij=0,i7=0,i;
	int len=s.size();
	string other="";
	for(i=0;i<len;++i)
	{
		switch(s.at(i))
		{
			case 'Z': ++iz; break;
			case 'O': ++io; break;
			case 'J': ++ij; break;
			case '7': ++i7; break;
			default: other+=s.at(i);break;
		}
	}
	s.clear();
	s.append(iz,'Z');//ÏëÄ©Î²×·¼Ó×Ö·û
	s.append(io,'O');
	s.append(ij,'J');
	s.append(i7,'7');
	s.append(other);
	return s;
}
int main()
{
	string str;
	while(cin>>str)
	{
		cout<<sort(str)<<endl;
	}
	return 0;
}
