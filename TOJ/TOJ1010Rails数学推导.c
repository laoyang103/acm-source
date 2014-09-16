#include<stdio.h>
int arr[1024];//存贮输入的数
int main()
{
    int len,i;
    int max;//记录前几组数中，最大的数
    int yes;//标记是否可行
    while(scanf("%d",&len),len)//逗号表达式，返回右边的值，当len为0时，循环终止
    {
        while(scanf("%d",arr),arr[0])
        {
            max=arr[0];
            yes=1;
            for(i=1;i<len;++i)
            {
                scanf("%d",arr+i);
                if(yes && arr[i]>arr[i-1] && arr[i]<max) yes=0;
                else if(arr[i]>max) max=arr[i];
            }
            if(yes) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
