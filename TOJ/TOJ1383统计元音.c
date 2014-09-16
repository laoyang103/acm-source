#include <stdio.h>
int map[128];//统计每个字符出现的次数
char input[101];
int main()
{
	int n;
	char *p=NULL;
	scanf("%d",&n);
	getchar();
	while(0 != n)
	{
		map['a']=0;
		map['e']=0;
		map['i']=0;
		map['o']=0;
		map['u']=0;
		p=gets(input);
		while(0 != (*p))
		{
			++map[(*p)];
			++p;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",
				map['a'],map['e'],map['i'],map['o'],map['u']);
		--n;
		if(n > 0)printf("\n");
	}
	return 0;
}
