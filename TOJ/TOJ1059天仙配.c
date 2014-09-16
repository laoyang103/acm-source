#include<stdio.h>
int square[20000];//方格数据
int main()
{
    int n;//人数
    int i,j;
    int count;//计数
    int manSum,womanSum;//男、女分数
    while(scanf("%d",&n),n)
    {
        n*=2;//计数方格总数
        for(i=0;i<n;++i)
            scanf("%d",square+i);
        i=0;//控制男的位置
        j=n-1;//控制女的位置
        manSum=womanSum=0;
        count=-1;//抛开manSum=womanSum=0的情况
        while(1)
        {
            if(manSum>womanSum)
            {
                if(j<0)break;
                womanSum+=square[j--];
            }
            if(manSum<womanSum)
            {
                if(i>=n)break;
                manSum+=square[i++];
            }
            if(manSum==womanSum)
            {
                ++count;
                if(i>=n || j<0)break;
                manSum+=square[i++];
                womanSum+=square[j--];
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
