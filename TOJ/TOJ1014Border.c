#include <stdio.h>
#include <string.h>
char bitmap[32][33];//λͼ
char direction[256];//��������,·��
int main()
{
    int testCount=0;//������������
    int x=0,y=0;//��ǰ������
    int i,j;
    int length=0;//�������鳤�ȣ�Ҫ�ƶ��Ĵ���
    scanf("%d",&testCount);
    for(i=1;i<=testCount;++i)
    {
        memset(bitmap,'.',sizeof(bitmap));
        scanf("%d%d",&x,&y);
        scanf("%s",direction);
        length=strlen(direction)-1;//ȥ������'.'
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
            else if('N'==direction[j])//Ϊ�����鴦���㣬���ϱ��ߵ��Ŵ���
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
        for(y=31;y>=0;--y)//�����鵹�����
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
