#include <stdio.h>
int main()
{
	//以下定义3组复数
	double a1,b1;
	double a2,b2;
	double a3,b3;
	double temp;
	char oper[2];//运算符
	int testCases;//测试组数
	scanf("%d",&testCases);
	while(testCases--)
	{
		scanf("%lf%lf",&a1,&b1);
		scanf("%s",oper);
		scanf("%lf%lf",&a2,&b2);
		switch(oper[0])
		{
			case '+':
			{
				a3=a1+a2;
				b3=b1+b2;
				break;
			}
			case '-':
			{
				a3=a1-a2;
				b3=b1-b2;
				break;
			}
			case '*':
			{
				a3=a1*a2-b1*b2;
				b3=a1*b2+b1*a2;
				break;
			}
			case '/':
			{
				temp=a2*a2+b2*b2;
				a3=(a1*a2+b1*b2)/temp;
				b3=(b1*a2-a1*b2)/temp;
				break;
			}
			default:break;
		}
		if(0 == a3)
		{
			if(0 == b3)
			{
				printf("0.0\n");
			}
			else if(1 == b3)
			{
				printf("i\n");
			}
			else if(-1 == b3)
			{
				printf("-i\n");
			}
			else
			{
				printf("%.1lfi\n",b3);
			}
		}
		else
		{
			if(b3 > 0)
			{
				if(1 == b3)
				{
					printf("%.1lf+i\n",a3);
				}
				else
				{
					printf("%.1lf+%.1lfi\n",a3,b3);
				}
			}
			else if(0 == b3)
			{
				printf("%.1lf\n",a3);
			}
			else
			{
				if(-1 == b3)
				{
					printf("%.1lf-i\n",a3);
				}
				else
				{
					printf("%.1lf%.1lfi\n",a3,b3);
				}
			}
		}
	}
	return 0;
}
