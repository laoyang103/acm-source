#include <stdio.h>
char map[][5]={"th","st","nd","rd","th","th","th","th","th","th"};
int main()
{
	int t;
	int d;
	int tens,units;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&d);
		units=d%10;
		tens=(d/10)%10;
		if(tens == 1)
		{
			printf("%dth\n",d);
		}
		else
		{
			printf("%d%s\n",d,map[units]);
		}
	}
	return 0;
}
