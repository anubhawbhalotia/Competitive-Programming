 #include <bits/stdc++.h>
using namespace std;
int main()
{
	long n,r,t,i,max,min;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		long a[n];
		max=0;
		min=1000000000;
		for(i=0;i<n;i++)
		{
			cin>>a[i];

		}
		for(i=0;i<n-1;i++)
		{
			if(a[i]<r)
			{
				if(a[i]>=max)
				{
					max=a[i];
				}
				else
				{
					cout<<"NO\n";
					break;
				}
			}
			else
			{
				if(a[i]<=min)
				{
					min=a[i];
				}
				else
				{
					cout<<"NO\n";
					break;
				}
			}
		}
		if(i==n-1)
		{
			cout<<"YES\n";
		}

	}
}