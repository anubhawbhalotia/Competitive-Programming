#include<bits/stdc++.h>
using namespace std;
long gcd(long a,long b)
{
	if(a==0)
	{
		return b;
	}
	return gcd(b%a,a);
}
int main()
{
	long n,i,b;
	cin>>n;
	long a[n];
	long max=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	b=gcd(a[0],a[1]);
	for(i=2;i<n;i++)
	{
		b=gcd(a[i],b);
	}
	
	if(((max/b)-n)%2==0)
	{
		cout<<"Bob";
	}
	else
	{
		cout<<"Alice";
	}
}