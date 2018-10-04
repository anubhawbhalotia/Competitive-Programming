#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,m;
	scanf("%ld %ld",&n,&m);
	long a[n],b[m];
	for(long i=0;i<n;i++)
		scanf("%ld",&a[i]);
	for(long i=0;i<m;i++)
		scanf("%ld",&b[i]);
	long long x;
	scanf("%lld",&x);
	long long min;
	long long ansA[3000]={},ansB[3000]={};
	long long s=0;
	for(long i=1;i<=n;i++)
	{
		min=100000000;
		s=0;
		for(long j=0;j<i;j++)
		{
			s+=a[j];
		}
		if(s<min)
			min=s;
		for(long j=i;j<n;j++)
		{
			s-=a[j-i];
			s+=a[j];
			if(s<min)
				min=s;
		}
		ansA[i-1]=min;
	}
	for(long i=1;i<=m;i++)
	{
		min=100000000;
		s=0;
		for(long j=0;j<i;j++)
		{
			s+=b[j];
		}
		if(s<min)
			min=s;
		for(long j=i;j<m;j++)
		{
			s-=b[j-i];
			s+=b[j];
			if(s<min)
				min=s;
		}
		ansB[i-1]=min;
	}
	// for(long i=0;i<n;i++)
	// {
	// 	cout<<ansA[i]<<" ";
	// }
	// cout<<endl;
	// for(long i=0;i<m;i++)
	// {
	// 	cout<<ansB[i]<<" ";
	// }
	// cout<<endl;
	long long maxTemp=0,max=0;
	for(long i=0;i<n;i++)
	{
		maxTemp=-1;
		for(long j=0;j<m;j++)
		{
			if(ansA[i]*ansB[j]<=x)
			{
				maxTemp=j;
			}
			else
			{
				break;
			}
		}
		if(((i+1)*(maxTemp+1))>max && maxTemp!=-1)
		{
			max=(i+1)*(maxTemp+1);
			//cout<<"max="<<max<<endl;
		}
	}
	cout<<max<<endl;


}