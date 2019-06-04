#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long a[n];
	for(long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long ans=0;
	for(long i=0;i<n;i++)
	{
		long temp=0;
		for(long j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				temp++;
			}
		}
		ans+=temp;
	}
	long m,l,r;
	cin>>m;
	int s=1;
	if(ans%2==0)
	{
		s=0;
	}
	while(m--)
	{
		cin>>l>>r;
		if(((r-l+1)/2)%2==1)
		{
			s=(s==0)?1:0;
			
		}
		if(s)
			cout<<"odd"<<endl;
		else
			cout<<"even"<<endl;
	}
}