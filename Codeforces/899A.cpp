#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,t=0,o=0,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a==2)
		{
			t++;
		}
		else
		{
			o++;
		}
	}
	if(t==o)
	{
		cout<<t;
	}
	else
		if(t>o)
		{
			cout<<o;
		}
		else
		{
			cout<<t+((o-t)/3);
		}
}
