#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long maxx=0,minn=1000000001,n,i,j,maxxc=0,minnc=0;
	cin>>n;
	long long a[200005];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>maxx)
		{
			maxx=a[i];
		}
		if(a[i]<minn)
		{
			minn=a[i];	
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==maxx)
		{
			maxxc++;
		}
		if(a[i]==minn)
		{
			minnc++;
		}
	}
	if(maxx!=minn)
	{
		cout<<maxx-minn<<" "<<minnc*maxxc;
	}
	else
	{
		long long z=n*(n-1);
		z=z/2;
		cout<<"0 "<<z;
	}
}