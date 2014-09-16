#include<iostream>
using namespace std;
int rail[1024];
int mark[1024];
int len;
void GetMinOfRight()//获得右边比他小的数的个数
{
    for(int i=len-1;i>=0;--i)
    {
        mark[i]=0;
        for(int j=i+1;j<len;++j)
            if(rail[i]>rail[j])
                ++mark[i];
    }
}
int main()
{
	int i,j;
    while(cin>>len,len)
    {
        while(1)
        {
            cin>>rail[0];
            if(rail[0]==0)
                break;
            for(i=1;i<len;++i)
                cin>>rail[i];
            GetMinOfRight();
            bool fail=false;
            for(i=0;i<len-1;++i)
            {
                for(j=i+1;j<len;++j)
                {
                    if(rail[i]>rail[j])
                    {
                        if(mark[i]-mark[j]>1)
                        {
                            fail=true;
                        }
                        break;
                    }
                }
                if(fail)
                    break;
            }
            if(fail)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
		cout<<endl;
    }
    return 0;
}
