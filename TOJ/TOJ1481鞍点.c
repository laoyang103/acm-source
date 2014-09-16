#include <stdio.h>
#include <string.h>
typedef struct
{
	int row;//��
	int col;//��
}Point;
Point point;//����
int markRowMax[10];//��¼���е����ֵ
int markColMin[10];//��¼���е���Сֵ
int array[10][10];
int row,col;//�����С���
int GetMaxInRow(int r)//���һ���е����ֵ�к�
{
	int i;
	int max=array[r][0];
	int maxIndex=0;
	//�ҵ�r���е����ֵ
	for(i=1;i<col;++i)
	{
		if(max < array[r][i])
		{
			max=array[r][i];
			maxIndex=i;
		}
	}
	return maxIndex;
}
int IsMinInCol(int c,int data)//�ж�data���Ƿ���c���е���Сֵ
{
	int i;
	int min;
	int minIndex;
	if(markColMin[c] == -1)
	{
		min=array[0][c];
		minIndex=0;
		//�ҵ�c���е���Сֵ
		for(i=1;i<row;++i)
		{
			if(min > array[i][c])
			{
				min=array[i][c];
				minIndex=i;
			}
		}
		markColMin[c]=minIndex;
	}
	if(data == markColMin[c])return 1;
	else return 0;
}
int GetPoint()
{
	int i,j;
	int c;
	for(i=0;i<row;++i)
	{
		c=GetMaxInRow(i);//���i�������ֵ���б�
		if(IsMinInCol(c,i))//�ж�[i,c]�Ƿ���c������Сֵ
		{
			point.row=i;
			point.col=c;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int i,j;
	scanf("%d%d",&row,&col);
	for(i=0;i<row;++i)
	{
		for(j=0;j<col;++j)
		{
			scanf("%d",array[i]+j);
		}
	}
	memset(markColMin,-1,sizeof(markColMin));
	if(0 == GetPoint())
	{
		puts("None");
	}
	else
	{
		printf("Array[%d][%d]=%d\n",point.row,point.col,
				array[point.row][point.col]);
	}	
	return 0;
}
