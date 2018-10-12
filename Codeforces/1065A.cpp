#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long s,a,b,c;
		long long ans=0;
		scanf("%lld %lld %lld %lld",&s,&a,&b,&c);
		long long pc=a*c;
		ans+=(s/pc)*(a+b);
		s=(s%pc);
		ans+=(s/c);
		printf("%lld\n",ans);
	}

}