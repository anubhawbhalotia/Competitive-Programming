#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	long long x,f;
	scanf("%ld",&n);
	long a[n];
	long long ans=0;
	for(long i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}	
	scanf("%lld %lld",&x,&f);
	for(long i=0;i<n;i++)
	{
		if(a[i]>x)
		{
			ans+=f*((ceil)(((long long)(a[i])-x)/(long double)(x+f)));
		}
	}
	cout<<ans<<endl;
}