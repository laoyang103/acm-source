#include<stdio.h>
int box[50];//������������
int main()
{
    int number=1;//��¼������������
    int len,i;
    int aver;//�����������ƽ��ֵ
    int count;//�ƶ��Ĵ���
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
