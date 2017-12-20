#include <bits/stdc++.h>
using namespace std;
long pbank(long n,long a[],long p[],long w[],long l)
{
	long i,cost,temp;
	if(l==0)
	{
		return 0;
	}
	if(a[l])
	{
		return a[l];
	}
	long min=1000000000;
	for(i=0;i<n;i++)
	{
		if(w[i]>l)
		{
			continue;
		}
		temp=pbank(n,a,p,w,l-w[i]);
		if(temp!=-1)
		{
			cost=p[i]+pbank(n,a,p,w,l-w[i]);
			if(cost<min)
			{
				min=cost;
			}
		}
	}
	if(min==1000000000)
	{
		a[l]=-1;
		return a[l];
	}
	a[l]=min;
	return a[l];
}
int main()
{
	long t,e,f,n,i,cost;
	cin>>t;
	while(t--)
	{    
		cin>>e>>f;
		cin>>n;
		long p[n],w[n],a[100000]={};
		for(i=0;i<n;i++)
		{
		 	cin>>p[i]>>w[i];
		}
		cost=pbank(n,a,p,w,f-e);
		if(cost==-1)
		{
			cout<<"This is impossible."<<endl;
		}
		else
		{
			cout<<"The minimum amount of money in the piggy-bank is "<<cost<<"."<<endl;
		}
	}
}