#include <stdio.h>
#include <string.h>

#define MAX_DATA_LENGTH 10000 //������󳤶�

//#define TEST
#ifdef TEST
#define MAX_NJ1 20
__int64 nj1[100];
#endif

int njnow[MAX_DATA_LENGTH+1];//��¼��ǰ�׳�ֵ
int njlast[MAX_DATA_LENGTH+1];//��¼�ϴν׳�ֵ

/*����ת�����ַ���
**a:��ת������
**bits:Ҫת����ʮ����λ��
**destStr:Ŀ���ַ���
*/
char* itoa(int a,int bits,char *destStr)
{
	int i;
	for(i=bits-1;i>=0;--i)
	{
		destStr[i]=a%10+48;
		a/=10;
	}
	return destStr;
}

/* �������˷�
** now:��Ž��
** last:��������������
** len:ʹ�õ�������λ��
** n:����
** ����ֵ:ʹ�õ�������λ��
*/
int mul(int now[],int last[],int len,int n)
{
	/*
	��la��lc�Ǵ�������b��32λ����
	������������100000������������100000��1����������ʹ��
	1
	la=la0*10^0+la1*10^5+la2*10^10+...��
	lc=la*b=lc0*10^0+lc1*10^5+lc2*10^10...
	lc0=la0*b%10^5
	lc1=la1*b%10^5+la0*b/10^5
	lc2=la2*b%10^5+la1*b/10^5
	*/
	int i;
	for(i=0;i<len;++i)
	{
		now[i] += last[i]*n;
		now[i+1] = now[i]/100000;
		now[i] %= 100000;
	}
	if(now[i] !=0 )++len;
	return len;
}

/* ���n�Ľ׳�ֵ
** pLength:����õ�������λ��
** ����ֵ���������ָ��
*/
int* getNJ(int n,int *pLenth)
{
	int i;
	int *pNow=njnow;
	int *pLast=njlast;
	int *pTemp=NULL;
	int len=1;
	pNow[0]=1;
	for(i=1;i<=n;++i)
	{
		pTemp=pNow;
		pNow=pLast;
		pLast=pTemp;
		memset(pNow,0,sizeof(int)*len);
		len=mul(pNow,pLast,len,i);
	}
	*pLenth=len;
	return pNow;
}

#ifdef TEST
/*ʹ��64λ����������׳�
*/
void setNJ()
{
	int i;
	nj1[0]=1;
	for(i=1;i<=MAX_NJ1;++i)
	{
		nj1[i]=i*nj1[i-1];
	}
}
#endif

int main()
{
	int n,i;
	char temp[10];
	int *pNJ=NULL;
	int len=0;
#ifdef TEST
	setNJ();
#endif
	memset(temp,0,sizeof(temp));
	while(scanf("%d",&n) == 1)
	{
#ifdef TEST
		if(n<=MAX_NJ1)
			printf("%I64d\n",nj1[n]); //���ڱȽϴ�������������ȷ��
#endif
		pNJ=getNJ(n,&len);
		printf("%d",pNJ[len-1]); //�Ƚ���λ����������ʽ������Ժ���ǰ��0
		for(i=len-2;i>=0;--i)//�������������ת��Ϊ5λ�ַ������
		{
			printf("%s",itoa(pNJ[i],5,temp));
		}
		printf("\n");
	}
	return 0;
}
