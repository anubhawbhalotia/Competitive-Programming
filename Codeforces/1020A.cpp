#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	for(long i=0;i<k;i++)
	{
		long ta,fa,tb,fb;
		scanf("%ld %ld %ld %ld",&ta,&fa,&tb,&fb);
		long long ans=0;
		long curr;
		if(ta==tb)
		{
			ans=abs(fa-fb);
		}
		else 
		{
			if(fa<a || fa>b)
			{
				if(abs(fa-a)<abs(fa-b))
				{
					curr=a;
				}
				else
				{
					curr=b;
				}
				ans+=abs(fa-curr);
				ans+=abs(tb-ta);
				ans+=abs(fb-curr);
			}
			else 
			{
				ans+=abs(ta-tb);
				ans+=abs(fb-fa);
			}
			
		}
		printf("%lld\n",ans);
	}
}