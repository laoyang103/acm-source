#include<stdio.h>
int arr[1024];//�����������
int main()
{
    int len,i;
    int max;//��¼ǰ�������У�������
    int yes;//����Ƿ����
    while(scanf("%d",&len),len)//���ű��ʽ�������ұߵ�ֵ����lenΪ0ʱ��ѭ����ֹ
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
