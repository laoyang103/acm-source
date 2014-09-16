#include<stdio.h>
#include<string.h>
int result[1004];//���
char tempResult[500][504];//��ʱ���
char opcode;//������
char operand1[502];//�������
char operand2[502];//�Ҳ�����
char input[1004];//����
int leftLength=0;//��������ĳ���
int rightLength=0;//�Ҳ������ĳ���
int resultLength=0;//����ĳ���
int maxLength=0;//����������Ҳ�����+�����롢������ȵ����ֵ
void Add()//�߾��ȼӷ�
{//ԭ����ԭ��������ת���м��㣬�������ڽ�λ�ͽ�λ��
	int length=leftLength;
	int i=0;
	int temp=0;
	if(length<rightLength)//�����󳤶�
		length=rightLength;
	for(i=0;i<length;++i)
	{
		result[i]=operand1[i]+operand2[i];//ִ�����
	}
	//��λ
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
void Sub()//�߾��ȼ���
{
	int i,len;
	for(i=0;i<leftLength;++i)
	{
		result[i]=operand1[i]-operand2[i];//ִ�����
	}
	len=leftLength-1;
	while(result[len]<=0)--len;//����õ����ĳ���
	for(i=0;i<len;++i)
	{
		if(result[i]<0)
		{
			result[i]+=10;//��λ����
			result[i+1]-=1;
		}
	}
	len=leftLength-1;
	while(result[len]<=0)--len;//��������
	resultLength=len+1;
}
void Mutiply()//�߾��ȳ˷�
{
	int i,j,temp;
	for(i=0;i<rightLength;++i)
	{
		for(j=0;j<leftLength;++j)
		{
			if(result[i+j]==-1)
				result[i+j]=0;
			tempResult[i][j]=operand1[j]*operand2[i];//�����м���
			result[i+j]+=tempResult[i][j];//������
			if(operand2[i]==0)//�Ҳ�������λΪ0������Ҫ�����ж���
				break;
		}
	}
	//�����λ
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
		//�ж�����������
		ptr=strchr(input,'+');
		if(!ptr)
		{
			ptr=strchr(input,'-');
			if(!ptr)
			{
				ptr=strchr(input,'*');
				opcode='*';//��
			}
			else opcode='-';//��
		}
		else opcode='+';//��
		memset(operand1,0,sizeof(operand1));//����������1
		memset(operand2,0,sizeof(operand2));//����������2
		leftLength=ptr-input;//�����������
		rightLength=length-leftLength-1;//�Ҳ������ĳ���
		for(i=0;i<leftLength;++i)//���������ת��Ϊ����
		{
			operand1[i]=input[leftLength-i-1]-48;
		}
		for(i=0;i<rightLength;++i)//���Ҳ�����ת��Ϊ����
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
		maxLength=resultLength;//����Ҫ��ʾ����󳤶�
		if(maxLength<tempLength)
			maxLength=tempLength;
		//����������
		for(i=0;i<maxLength-leftLength;++i)
			printf(" ");//ǰ���ո�
		for(i=leftLength-1;i>=0;--i)
			printf("%c",operand1[i]+48);
		printf("\n");
		//����Ҳ�����
		for(i=0;i<maxLength-rightLength-1;++i)//��һ��������λ
			printf(" ");//ǰ���ո�
		printf("%c",opcode);
		for(i=rightLength-1;i>=0;--i)
			printf("%c",operand2[i]+48);
		printf("\n");
		//���-
		if(opcode!='*' ||(opcode=='*' && rightLength==1))
		{
			tempLength=maxLength;
		}
		for(i=0;i<maxLength-tempLength;++i)
			printf(" ");//ǰ���ո�	
		for(i=0;i<tempLength;++i)
			printf("-");
		printf("\n");
		//����˷����м���
		if(opcode=='*' && rightLength>1)
		{
			//����м���
			for(i=0;i<rightLength;++i)
			{
				//��λ
				j=0;
				tempLength=0;
				while(tempResult[i][j]!=-1)
				{//���м����Ľ�λ
					temp=tempResult[i][j]/10;
					if(tempResult[i][j+1]==-1 && temp!=0)
						tempResult[i][j+1]=0;
					tempResult[i][j+1]+=temp;
					tempResult[i][j]%=10;
					tempResult[i][j]+=48;
					++j;
				}
				tempLength=j;//�м����ĳ���
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
		//������
		for(i=0;i<maxLength-resultLength;++i)
			printf(" ");
		for(i=resultLength-1;i>=0;--i)
			printf("%d",result[i]);
		printf("\n\n");
	}
	return 0;
}
