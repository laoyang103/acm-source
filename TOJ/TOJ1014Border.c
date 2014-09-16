#include <stdio.h>
#include <string.h>
char bitmap[32][33];//位图
char direction[256];//方向数组,路径
int main()
{
    int testCount=0;//测试数据组数
    int x=0,y=0;//当前点坐标
    int i,j;
    int length=0;//方向数组长度，要移动的次数
    scanf("%d",&testCount);
    for(i=1;i<=testCount;++i)
    {
        memset(bitmap,'.',sizeof(bitmap));
        scanf("%d%d",&x,&y);
        scanf("%s",direction);
        length=strlen(direction)-1;//去掉最后的'.'
        for(j=0;j<length;++j)
        {
            if('E'==direction[j])
            {
                bitmap[y-1][x]='X';
                ++x;
            }
            else if('W'==direction[j])
            {
                bitmap[y][x-1]='X';
                --x;
            }
            else if('N'==direction[j])//为了数组处理方便，将南北颠倒着处理
            {
                bitmap[y][x]='X';
                ++y;
            }
            else if('S'==direction[j])
            {
                bitmap[y-1][x-1]='X';
                --y;
            }
        }
        printf("Bitmap #%d\n",i);
        for(y=31;y>=0;--y)//将数组倒着输出
        {
            for(x=0;x<32;++x)
                printf("%c",bitmap[y][x]);
            printf("\n");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
