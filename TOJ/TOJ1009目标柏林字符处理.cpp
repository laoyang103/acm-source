#include <cstdio>
#include <cstring>
char str[1001];//加密的字符串
int length;//字符串长度
void ToLeft(int width)//向左旋转
{
    int i;
	char temp=str[width-1];//保存第一个是width倍数的元素，
    //注意数组下标从0开始，而题目的倍数是相对于从1开始而言的 
	for(i=width-1;i+width<length;i+=width)//每次增加width个下标 
		str[i]=str[i+width]; //按倍数依次左移 
	str[i]=temp;//将最左边的字符放到最右边 
}
void ToRight(int width)//向右旋转
{
    int i;
	int t=length/width*width;
	char temp=str[t-1];
	for(i=t-1;i-width>=0;i-=width)
		str[i]=str[i-width];
	str[i]=temp;
}
int main()
{
	while(gets(str))
	{
		length=strlen(str);
		for(int i=length;i>0;--i)
			if(i%2!=0)//奇数步左旋（逆时针）
				ToLeft(i);
			else
				ToRight(i);
		printf("%s\n",str);
	}
	return 0;
}
