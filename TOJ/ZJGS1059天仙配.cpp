#include<iostream>
using namespace std;
int main()
{
	int a[20000];
	int n,count;
	int i, j;
	int msum,wsum;
	int oldi;
	while(cin>>n)
	{
		if(n==0)
			break;
		n*=2;
		count=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		msum=a[0];
		wsum=a[n-1];
		i=1;
		j=n-2;
		oldi=-1000;
		while(1)
		{
			if(msum>wsum)
			{
				if(j<0)
					break;
				wsum+=a[j];
				j--;
			}
			if(msum<wsum)
			{
				if(i>=n)
					break;
				msum+=a[i];
				i++;
			}
			if(msum==wsum)
			{
				count++;
				if(i>=n || j<0)
					break;
				msum+=a[i];
				wsum+=a[j];
				oldi=i;
				i++;
				j--;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
