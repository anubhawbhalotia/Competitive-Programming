#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		double cmax=0;
		long max=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]+a[j]>max)
				{
					max=a[i]+a[j];
					cmax=1;
				}
				else if(a[i]+a[j]==max)
				{
					cmax++;
				}
			}
		}
		double m=n;
		cout<<cmax/((m*(m-1))/2)<<endl;
	}
}