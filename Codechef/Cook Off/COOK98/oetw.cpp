#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	long long ans,s;
	while(t--)
	{
		long n;
		cin>>n;
		long a[n];
		s=0;
		long long ans=0;
		for(long i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			s+=a[i];
		}
		long p1=0;
		long p2=n-1;
		if(a[p1]==2 && a[p2]==2)
		{
			long i,j;
			long long s1=s,s2=s;
			long ans1=0,ans2=0;
			for(i=p1;i<n;i++)
			{
				if(a[i]==1)
				{
					break;
				}
				s1-=2;
				ans1++;
			}
			for(j=p2;j>=0;j--)
			{
				if(a[j]==1)
				{
					break;
				}
				s2-=2;
				ans2++;
			}
			j=p2-j;
			if(i<=j)
			{
				ans=ans1+s1;
			}
			else if(i!=n)
			{
				ans=ans2+s2;
			}
			else
			{
				ans=ans1;
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<s<<endl;
		}

	}

}
