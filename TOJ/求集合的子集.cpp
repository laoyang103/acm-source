#include <cstdio>
#include <cmath>
int main()
{
	int i=0;
	int j=0;
	int n=pow(2,15);//n��ʾ�Ӽ��ϵ��ܸ���
	int bit=0;
	for(i=0;i<n;++i)
	{
		printf("{");
		for(j=0;j<26;++j)
		{
			bit=(i>>j)&1;
			if(bit)printf("%c",j+97);
		}
		printf("}\n");
	}
	return 0;
}
