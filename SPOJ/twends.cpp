#include <bits/stdc++.h>
using namespace std;
long count(long a[],int l,int r,long m[1000][1000])
{
	long m1,m2,x,y;
	if(r-l==1)
		return max(a[r]-a[l],a[l]-a[r]);
	x=a[l];
	if(a[l+1]>=a[r])
	{
		y=a[l+1];
		if(m[l+2][r])
			m1=m[l+2][r];
		else
		{
			m1=count(a,l+2,r,m);
			m[l+2][r]=m1;
		}
	}
	else
	{
		y=a[r];
		if(m[l+1][r-1])
			m1=m[l+1][r-1];
		else
		{
			m1=count(a,l+1,r-1,m);
			m[l+1][r-1]=m1;
		}
	}
	m1+=(x-y);
	x=a[r];
	if(a[l]>=a[r-1])
	{
		y=a[l];
		if(m[l+1][r-1])
			m2=m[l+1][r-1];
		else
		{
			m2=count(a,l+1,r-1,m);
			m[l+1][r-1]=m2;
		}
	}
	else
	{
		y=a[r-1];
		if(m[l][r-2])
			m2=m[l][r-2];
		else
		{
			m2=count(a,l,r-2,m);
			m[l][r-2]=m2;
		}
	}
	m2+=(x-y);
	return max(m1,m2);
}
int main()
{
	int n,i,c=1;
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		long m[1000][1000]={},a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<"In game "<<c++<<", the greedy strategy might lose by as many as "<<count(a,0,n-1,m)<<" points."<<endl;	
		
	}
}