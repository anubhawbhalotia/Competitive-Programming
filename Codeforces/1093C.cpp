#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long long s=0,e=1000000000000000001,b,a[n];
	for(long i=0;i<n/2;i++)
	{
		cin>>b;
		if(b-s<=e)
		{
			a[i]=s;
			a[n-i-1]=b-s;
		}
		else
		{
			a[n-i-1]=e;
			a[i]=b-e;
		}
		s=a[i];
		e=a[n-i-1];
	}
	for(long i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}