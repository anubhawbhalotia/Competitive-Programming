#include<bits/stdc++.h>
using namespace std;
long maxteam(long m,long n)
{
	if(m==0 || n==0 || (n+m)<3)
	{
		return 0;
	}
	if(m>=n)
	{
		return 1+maxteam(m-2,n-1);
	}
	else
	{
		return 1+maxteam(m-1,n-2);
	}
}
int main()
{
	long n,m;
	cin>>n>>m;
	cout<<maxteam(m,n);
}