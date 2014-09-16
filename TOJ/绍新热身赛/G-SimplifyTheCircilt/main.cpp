#include <cstdio>
#include <cstring>
char input[101];
int getNumber(char in[])
{
    int sum=0;
    int t=0;
    for(int i=0; i<strlen(in); ++i)
    {
        if(in[i] != '-')
        {
            t=t*10+in[i]-'0';
            if(in[i+1] == '-' || in[i+1] == 0)
            {
            	sum+=t;
				t=0;
            }
        }
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        double sum=0.0;
        while(n--)
        {
            scanf("%s",input);
            sum+=1.0/getNumber(input);
        }
        printf("%.2lf\n",1.0/sum);
    }
    return 0;
}
