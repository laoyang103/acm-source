#include<cstdio>
#include<cmath>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
        printf("%.0lf\n",ceil(log(double(n))/log(3.0)));
    return 0;
}
