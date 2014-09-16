#include<iostream>
#include<stack>
using namespace std;
int arr[1024];//存贮输入的数据
int main()
{
    stack<int> sta;//用栈来模拟车站
    int len,i;
    while(cin>>len && len)
    {
        while(cin>>arr[0] && arr[0])
        {
            for(i=1;i<len;++i)
                cin>>arr[i];
            int index=1;//未进站的车辆编号
            bool yes=true;//标记是否可行
            i=0;
            while(i<len)
            {
                if(index<arr[i])//未进站车辆编号比已出栈车辆编号小
                    sta.push(index++);//则车辆先进站，然后判断下一辆车
                else if(index>arr[i])//编号大
                {
                    if(!sta.empty() && sta.top()==arr[i])
                    {//如果栈非空，且栈顶车辆正好是要出栈的车辆，则出栈
                        sta.pop();
                        ++i;
                    }
                    else
                    {
                        yes=false;
                        break;
                    }
                }
                else
                {
                    ++i;
                    ++index;
                }

            }
            if(yes)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
