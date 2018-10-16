#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,a;
	scanf("%lld",&t);
	for(long i=0;i<t;i++)
	{
		long long ans=1;
		scanf("%lld",&a);
		while(a)
		{
			if(a&1)
				ans*=2;
			a=a>>1;
		}
		cout<<ans<<endl;

	}
}