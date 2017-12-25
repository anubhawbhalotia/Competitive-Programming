#include<bits/stdc++.h>
using namespace std;
#define M 1000000007 
int main()
{
	long n,k,i;
	cin>>n>>k;
	long long pre[n+1],a[n+1],s;
	if(n<=k)
	{
		cout<<"1";
		return 0;
	}
	a[0]=0;
	pre[0]=0;
	s=0;
	for(i=1;i<=k;i++)
	{
		a[i]=1;
		s=s+1;
	}
	for(i=k+1;i<=n;i++)
	{	
		s=s-a[i-k-1];
		a[i]=s%M;
		s=s+a[i];
		
	}
	printf("%lld",a[n]%M);
}