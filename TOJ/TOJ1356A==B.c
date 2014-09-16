#include <stdio.h>
#include <string.h>
char a[1024],b[1024];

//去掉实数尾部0
int formatTail(char *pStr)
{
	int len;
	if(strchr(pStr,'.') == NULL)//不是实数
	{
		return 0;
	}
	len=strlen(pStr)-1;
	//去掉尾部0
	while(pStr[len]=='0')
	{
		--len;
	}
	//去掉尾部的小数点
	if(pStr[len] == '.')
	{
		pStr[len]='\0';
	}
	else pStr[len+1]='\0';
	return 1;
}
//格式化首部
char* formatFront(char *pStr)
{
	char *p=pStr;
	if(*p == '-')//负数
	{
		//判断是否是0
		if(isEqual(p+1,"0")==1)
		{
			p[0]='\0';
		}
	}
	else
	{	//去掉前导0
		while(*p == '0')++p;
	}
	return p;
}
int isEqual(char *pa,char *pb)
{
	formatTail(pa);
	formatTail(pb);
	pa=formatFront(pa);
	pb=formatFront(pb);
	
//	printf("%s %s\n",pa,pb);测试格式化后的结果
	
	while(*pa!=0 && *pb!=0)
	{
		if(*pa != *pb)
		{
			return 0;
		}
		++pa;
		++pb;
	}
	if(*pa!=0 || *pb!=0)return 0;
	return 1;
}
int main()
{
	while(scanf("%s%s",a,b)!=EOF)
	{
		if(isEqual(a,b))puts("YES");
		else puts("NO");
	}
	return 0;
}
/*测试数据
1.0 1.00
1.0 1.100
1.1 1.100
0 0.0
-0 0
-0.0 0
-0 0.0
-0.123 0.123
012 12
123 123456
*/
