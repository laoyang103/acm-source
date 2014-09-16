#include <stdio.h>
int main()
{
	int t;
	int y;
	char fx[2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",fx,&y);
		if(fx[0]>='A' && fx[0]<='Z')
		{
			y += fx[0]-'A'+1;
		}
		else y -= (fx[0]-'a'+1);
		printf("%d\n",y);
	} 
	return 0;
}
