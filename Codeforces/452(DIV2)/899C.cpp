#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,z,s,i,a[100000],x;
	cin>>n;
	z=n*(n+1);
	z=z/2;
	if(z%2==0)
	{
		cout<<"0\n";
	}
	else
	{
		cout<<"1\n";
	}

		s=z/2;
		x=0;
		for(i=n;i>=1;i--)
		{
			if(s==0)
			{
				break;
			}
			if(i<=s)
			{
				a[x++]=i;
				s=s-i;
			}
		}
		cout<<x<<" ";
		for(i=0;i<x;i++)
		{
			cout<<a[i]<<" ";
		}
}

