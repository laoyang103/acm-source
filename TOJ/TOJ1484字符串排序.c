#include<stdio.h>
#include<string.h>
int main()
{
	char str[3][256],t[256];
	int i,j;
	scanf("%s%s%s",str[0],str[1],str[2]);
	for(i=0;i<2;++i)
	{
		for(j=i;j<3;++j)
		{
			if(strcmp(str[i],str[j])>0)
			{
				strcpy(t,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],t);
			}
		}
	}
	printf("%s %s %s",str[0],str[1],str[2]);
	return 0;
}
