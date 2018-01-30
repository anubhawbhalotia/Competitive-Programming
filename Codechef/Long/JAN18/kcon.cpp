#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
long a[300001];
int main()
{
	int t;
	long n,k,maxn,i,start,end;
	long long sum,max,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld %ld",&n,&k);
		sum=0;
		maxn=-100000000;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			sum+=a[i];
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
			if(k!=1)
			{
				a[n+i]=a[i];
			}
		}
		max=-10000000;
		s=0;
		start=-1;
		if(k!=1)
		{
			for(i=0;i<2*n;i++)
			{
				if(s+a[i]>0)
				{
					if(start==-1)
					{
						start=i;
					}
					s+=a[i];
 
				}
				else
				{
					start=-1;
					s=0;
				}
				if(s>max)
				{
					end=i;
					max=s;
				}
			}
			if(max==0)
			{
				printf("%ld\n",maxn);
				continue;
			}
			if(start<n && end>=n && sum>0 && k>2)
			{
				printf("%lld\n",max+ ((k-2)*sum));
				continue;
			}
			if(max>(sum*k))
			{
				printf("%lld\n",max);
			}
			else
			{
				printf("%lld\n",sum*k);
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(s+a[i]>0)
				{
					s+=a[i];
				}
				else
				{
					s=0;
				}
				if(s>max)
				{
					max=s;
				}
			}
			if(max==0)
			{
				printf("%ld\n",maxn);
				continue;
			}
			printf("%lld\n",max);
		}
	}
}
