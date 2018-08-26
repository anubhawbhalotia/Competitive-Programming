#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(long tt=1;tt<=t;tt++)
	{
		int n,k;
		cin>>n>>k;
		long a[n];
		for(int i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
		}
		sort(a,a+n);
		int day=1;
		int i=0;
		int flag=0;
		int count=0;
		while(i!=n)
		{
			int temp=k;
			flag=0;
			while(temp-- && i!=n)
			{
				if(a[i]>=day)
				{
					count++;
					i++;
				}
				else
				{
					temp++;
					i++;
				}
			}
			day++;
		}	
		cout<<"Case #"<<tt<<": "<<count<<endl;

	}
}