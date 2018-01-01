#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod=1e9 +7;
int main()
{
	int t,n,i,j;
	ll m,tmp;
	cin>>t;
	while(t--)
	{
		scanf("%d %lld",&n,&m);
		ll a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]<a[j])
				{
					tmp=a[i];
					a[i]=a[j];
					a[j]=tmp;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			m-=a[i];
			if(m<=0)
			{
				break;
			}
		}
		if(i==n)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",i+1);
		}
	}
}

		