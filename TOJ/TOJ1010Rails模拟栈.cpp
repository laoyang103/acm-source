#include<iostream>
#include<stack>
using namespace std;
int arr[1024];//�������������
int main()
{
    stack<int> sta;//��ջ��ģ�⳵վ
    int len,i;
    while(cin>>len && len)
    {
        while(cin>>arr[0] && arr[0])
        {
            for(i=1;i<len;++i)
                cin>>arr[i];
            int index=1;//δ��վ�ĳ������
            bool yes=true;//����Ƿ����
            i=0;
            while(i<len)
            {
                if(index<arr[i])//δ��վ������ű��ѳ�ջ�������С
                    sta.push(index++);//�����Ƚ�վ��Ȼ���ж���һ����
                else if(index>arr[i])//��Ŵ�
                {
                    if(!sta.empty() && sta.top()==arr[i])
                    {//���ջ�ǿգ���ջ������������Ҫ��ջ�ĳ��������ջ
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
