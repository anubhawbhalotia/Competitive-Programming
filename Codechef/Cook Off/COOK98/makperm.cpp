#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long n;
		cin>>n;
		long a[n];
		long c=0;
		long f[100100]={};
		for(long i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			if(a[i]>n)
			{
				c++;
			}
			else if(f[a[i]]==0)
			{
				f[a[i]]=1;
			}
			else
			{
				c++;
			}
		}
		cout<<c<<endl;
	}
}