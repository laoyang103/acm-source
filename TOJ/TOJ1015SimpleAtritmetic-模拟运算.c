#include<stdio.h>
#include<string.h>
int result[1004];//结果
char tempResult[500][504];//临时结果
char opcode;//操作码
char operand1[502];//左操作数
char operand2[502];//右操作数
char input[1004];//输入
int leftLength=0;//左操作数的长度
int rightLength=0;//右操作数的长度
int resultLength=0;//结果的长度
int maxLength=0;//左操作数、右操作数+操作码、结果长度的最大值
void Add()//高精度加法
{//原理，将原操作数反转进行计算，这样便于进位和借位。
	int length=leftLength;
	int i=0;
	int temp=0;
	if(length<rightLength)//获得最大长度
		length=rightLength;
	for(i=0;i<length;++i)
	{
		result[i]=operand1[i]+operand2[i];//执行相加
	}
	//进位
	i=0;
	while(result[i]!=-1)
	{
		temp=result[i]/10;
		if(result[i+1]==-1 && temp!=0)
			result[i+1]=0;
		result[i+1]+=temp;
		result[i]%=10;
		++i;
	}
	resultLength=i;
}
void Sub()//高精度减法
{
	int i,len;
	for(i=0;i<leftLength;++i)
	{
		result[i]=operand1[i]-operand2[i];//执行想减
	}
	len=leftLength-1;
	while(result[len]<=0)--len;//求可用的数的长度
	for(i=0;i<len;++i)
	{
		if(result[i]<0)
		{
			result[i]+=10;//借位操作
			result[i+1]-=1;
		}
	}
	len=leftLength-1;
	while(result[len]<=0)--len;//求结果长度
	resultLength=len+1;
}
void Mutiply()//高精度乘法
{
	int i,j,temp;
	for(i=0;i<rightLength;++i)
	{
		for(j=0;j<leftLength;++j)
		{
			if(result[i+j]==-1)
				result[i+j]=0;
			tempResult[i][j]=operand1[j]*operand2[i];//保存中间结果
			result[i+j]+=tempResult[i][j];//计算结果
			if(operand2[i]==0)//右操作数该位为0，则不需要继续判断了
				break;
		}
	}
	//计算进位
	i=0;
	while(result[i]!=-1)
	{
		temp=result[i]/10;
		if(result[i+1]==-1 && temp!=0)
			result[i+1]=0;
		result[i+1]+=temp;
		result[i]%=10;
		++i;
	}
	resultLength=i;
}
int main()
{
	int times=0;
	int count=0;
	int length=0;
	int tempLength=0;
	int i,j;
	int temp=0;
	char* ptr=NULL;
	scanf("%d",&times);
	count=times;
	while(count--)
	{
		scanf("%s",input);
		length=strlen(input);
		//判断是那种运算
		ptr=strchr(input,'+');
		if(!ptr)
		{
			ptr=strchr(input,'-');
			if(!ptr)
			{
				ptr=strchr(input,'*');
				opcode='*';//乘
			}
			else opcode='-';//减
		}
		else opcode='+';//加
		memset(operand1,0,sizeof(operand1));//拷贝操作数1
		memset(operand2,0,sizeof(operand2));//拷贝操作数2
		leftLength=ptr-input;//左操作数长度
		rightLength=length-leftLength-1;//右操作数的长度
		for(i=0;i<leftLength;++i)//将左操作数转换为整数
		{
			operand1[i]=input[leftLength-i-1]-48;
		}
		for(i=0;i<rightLength;++i)//将右操作数转换为整数
		{
			operand2[i]=input[length-i-1]-48;
		}
		memset(tempResult,-1,sizeof(tempResult));
		memset(result,-1,sizeof(result));
		switch(opcode)
		{
			case '+':
				Add();
				break;
			case '-':
				Sub();
				break;
			case '*':
				Mutiply();
				break;
			default:break;
		}
		tempLength=rightLength+1;
		if(tempLength<leftLength)
			tempLength=leftLength;
		maxLength=resultLength;//计算要显示的最大长度
		if(maxLength<tempLength)
			maxLength=tempLength;
		//输出左操作数
		for(i=0;i<maxLength-leftLength;++i)
			printf(" ");//前导空格
		for(i=leftLength-1;i>=0;--i)
			printf("%c",operand1[i]+48);
		printf("\n");
		//输出右操作数
		for(i=0;i<maxLength-rightLength-1;++i)//有一个操作符位
			printf(" ");//前导空格
		printf("%c",opcode);
		for(i=rightLength-1;i>=0;--i)
			printf("%c",operand2[i]+48);
		printf("\n");
		//输出-
		if(opcode!='*' ||(opcode=='*' && rightLength==1))
		{
			tempLength=maxLength;
		}
		for(i=0;i<maxLength-tempLength;++i)
			printf(" ");//前导空格	
		for(i=0;i<tempLength;++i)
			printf("-");
		printf("\n");
		//输出乘法的中间结果
		if(opcode=='*' && rightLength>1)
		{
			//输出中间结果
			for(i=0;i<rightLength;++i)
			{
				//进位
				j=0;
				tempLength=0;
				while(tempResult[i][j]!=-1)
				{//求中间结果的进位
					temp=tempResult[i][j]/10;
					if(tempResult[i][j+1]==-1 && temp!=0)
						tempResult[i][j+1]=0;
					tempResult[i][j+1]+=temp;
					tempResult[i][j]%=10;
					tempResult[i][j]+=48;
					++j;
				}
				tempLength=j;//中间结果的长度
				for(j=0;j<maxLength-tempLength-i;++j)
					printf(" ");
				for(j=tempLength-1;j>=0;--j)
					printf("%c",tempResult[i][j]);
				printf("\n");
			}
			for(i=0;i<maxLength;++i)
				printf("-");
			printf("\n");
		}
		//输出结果
		for(i=0;i<maxLength-resultLength;++i)
			printf(" ");
		for(i=resultLength-1;i>=0;--i)
			printf("%d",result[i]);
		printf("\n\n");
	}
	return 0;
}
