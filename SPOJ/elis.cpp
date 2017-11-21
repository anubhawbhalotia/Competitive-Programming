#include <bits/stdc++.h>
using namespace std;
long sub(long a[],long b[],long n)
{
	long max=1,i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j] && b[i]<(b[j]+1))
			{
				b[i]=b[j]+1;
			}
		}
		if(b[i]>max)
		{
			max=b[i];
		}
	}
	return max;
}
int main()
{
	long n,m,i;
	cin>>n;
	long b[n],a[n];
	for(i=0;i<n;i++)
	{
		b[i]=1;
	}
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<sub(a,b,n)<<endl;
}