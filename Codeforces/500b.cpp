#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,t,curr;
	cin>>n>>t;
	long a[n+1];
	for(long i=1;i<=n-1;i++)
	{
		cin>>a[i];
	}
	curr=1;
	while(curr<t)
	{
		curr+=a[curr];
		if(curr==t)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}