#include<stdio.h>
int square[20000];//��������
int main()
{
    int n;//����
    int i,j;
    int count;//����
    int manSum,womanSum;//�С�Ů����
    while(scanf("%d",&n),n)
    {
        n*=2;//������������
        for(i=0;i<n;++i)
            scanf("%d",square+i);
        i=0;//�����е�λ��
        j=n-1;//����Ů��λ��
        manSum=womanSum=0;
        count=-1;//�׿�manSum=womanSum=0�����
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
