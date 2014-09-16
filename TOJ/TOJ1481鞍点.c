#include <stdio.h>
#include <string.h>
typedef struct
{
	int row;//行
	int col;//列
}Point;
Point point;//鞍点
int markRowMax[10];//记录行中的最大值
int markColMin[10];//记录列中的最小值
int array[10][10];
int row,col;//数组行、列
int GetMaxInRow(int r)//获得一行中的最大值列号
{
	int i;
	int max=array[r][0];
	int maxIndex=0;
	//找到r行中的最大值
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
int IsMinInCol(int c,int data)//判断data行是否是c列中的最小值
{
	int i;
	int min;
	int minIndex;
	if(markColMin[c] == -1)
	{
		min=array[0][c];
		minIndex=0;
		//找到c列中的最小值
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
		c=GetMaxInRow(i);//获得i行中最大值的列标
		if(IsMinInCol(c,i))//判断[i,c]是否是c列上最小值
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
