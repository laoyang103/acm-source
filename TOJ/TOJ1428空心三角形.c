#include <stdio.h>
int main()
{
	char letter[2];
	int n,i,j;
	scanf("%s",letter);
	while('@' != letter[0])
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			if(1 == i)
			{
				for(j=1;j<n;++j)
				{
					putchar(' ');
				}
				putchar(letter[0]);
			}
			else if(n == i)
			{
				for(j=1;j<=2*n-1;++j)
				{
					putchar(letter[0]);
				}
			}
			else
			{
				for(j=1;j<=n-i;++j)
				{
					putchar(' ');
				}
				putchar(letter[0]);
				for(j=1;j<=2*i-3;++j)
				{
					putchar(' ');
				}
				putchar(letter[0]);
			}
			printf("\n");
		}
		scanf("%s",&letter);
		if('@' != letter[0])
		{
			printf("\n");
		}
	}
}
