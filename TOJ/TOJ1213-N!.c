#include <stdio.h>
#include <string.h>

#define MAX_DATA_LENGTH 10000 //数据最大长度

//#define TEST
#ifdef TEST
#define MAX_NJ1 20
__int64 nj1[100];
#endif

int njnow[MAX_DATA_LENGTH+1];//记录当前阶乘值
int njlast[MAX_DATA_LENGTH+1];//记录上次阶乘值

/*整数转换成字符串
**a:待转换整数
**bits:要转换的十进制位数
**destStr:目标字符串
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

/* 大整数乘法
** now:存放结果
** last:存贮被乘数数组
** len:使用到的数组位数
** n:乘数
** 返回值:使用到的数组位数
*/
int mul(int now[],int last[],int len,int n)
{
	/*
	设la、lc是大整数，b是32位整数
	将大整数看成100000进制数，即逢100000进1，这样可以使用
	1
	la=la0*10^0+la1*10^5+la2*10^10+...。
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

/* 获得n的阶乘值
** pLength:存放用到的数组位数
** 返回值：结果数组指针
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
/*使用64位整数来计算阶乘
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
			printf("%I64d\n",nj1[n]); //用于比较大数运算结果的正确性
#endif
		pNJ=getNJ(n,&len);
		printf("%d",pNJ[len-1]); //先将高位数按整数格式输出，以忽略前导0
		for(i=len-2;i>=0;--i)//将后面的数依次转换为5位字符串输出
		{
			printf("%s",itoa(pNJ[i],5,temp));
		}
		printf("\n");
	}
	return 0;
}
