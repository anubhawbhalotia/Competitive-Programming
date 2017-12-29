#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,i,x,minn,min,d;
	cin>>n;
	long a[n+1];
	minn=1000000001;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<minn)
		{
			minn=a[i];
		}
	}

	for(i=0;i<n;i++)
	{
		if(a[i]==minn)
		{
			x=i;
			i++;
			break;
		}
	}
	min=1000000001;
	for(;i<n;i++)
	{
		if(a[i]==minn)
		{
			d=i-x;
			x=i;
			if(d<min)
			{
				min=d;
			}
		}
	}
	cout<<min;
}