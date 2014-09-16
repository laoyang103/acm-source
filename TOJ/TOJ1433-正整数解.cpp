#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num;
	int x,y,z;
	while(cin>>num)
	{
		int sq=(int)sqrt(num);
		for(x=1;x<=sq;++x)
		{
			for(y=x;y<=sq;++y)
			{
				for(z=y;z<=sq;++z)
				{
					if(num == x*x + y*y +z*z)
					{
						goto LOOP_END;
					}
				}
			}
		}
LOOP_END:
		printf("%d %d %d\n",x,y,z);
	}
	return 0;
}
