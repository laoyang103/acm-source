#include <stdio.h>
int main()
{
	char name[14];
	float score[7],average,max,min;
	int i;
	while(scanf("%f%f%f%f%f%f%f%s",score,score+1,score+2,score+3,score+4,score+5,score+6,name)!=EOF)
	{
		average=max=min=score[0];
		for(i=1;i<7;++i)
		{
			if(max<score[i])max=score[i];
			else if(min>score[i])min=score[i];
			average+=score[i];
		}
		average=(average-max-min)/5.0f;
		printf("%s %0.2f\n",name,average);
	}
	return 0;
}