#include<stdio.h>
int box[50];//存贮输入数据
int main()
{
    int number=1;//记录测试数的组数
    int len,i;
    int aver;//求输入的数的平均值
    int count;//移动的次数
    while(scanf("%d",&len),len)
    {
        aver=count=0;
        for(i=0;i<len;++i)
        {
            scanf("%d",box+i);
            aver+=box[i];
        }
        aver/=len;
        for(i=0;i<len;++i)
        {
            if(box[i]>aver)
            {
                count+=box[i]-aver;
            }
        }
        printf("Set #%d\n",number);
        printf("The minimum number of moves is %d.\n\n",count);
        ++number;
    }
    return 0;
}
