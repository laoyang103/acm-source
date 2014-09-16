#include <stdio.h>
double scoreList[51][6];
int students,classes;
int main()
{
	int i,j;
	double average;
	int counter;
	while(scanf("%d%d",&students,&classes)!=EOF)
	{
		for(i=1;i<=students;++i)
		{
			average=0.0;
			for(j=1;j<=classes;++j)
			{
				scanf("%lf",&scoreList[i][j]);
				average+=scoreList[i][j];
			}
			scoreList[i][0]=average/classes;//求每个学生的平均成绩
		}
		//输出每个学生的平均成绩
		for(i=1;i<students;++i)
		{
			printf("%.2lf ",scoreList[i][0]);
		}
		printf("%.2lf\n",scoreList[i][0]);
		//求每门课的平均成绩
		for(i=1;i<=classes;++i)
		{
			average=0.0;
			for(j=1;j<=students;++j)
			{
				average+=scoreList[j][i];
			}
			scoreList[0][i]=average/students;
		}
		for(i=1;i<classes;++i)
		{
			printf("%.2lf ",scoreList[0][i]);
		}
		printf("%.2lf\n",scoreList[0][i]);
		//计算学生人数
		counter=0;
		for(i=1;i<=students;++i)
		{
			for(j=1;j<=classes;++j)
			{
				if(scoreList[i][j] < scoreList[0][j])
				{
					break;
				}
			}
			if(j>classes)
			{
				++counter;
			}
		}
		printf("%d\n\n",counter);
	}
	return 0;
}
