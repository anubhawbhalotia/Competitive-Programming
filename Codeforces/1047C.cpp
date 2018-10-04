#include<bits/stdc++.h>
using namespace std;
long int prime[16000001]={},freq[16000001]={};
long findGcd(long x,long y)
{
	if(y==0)
		return x;
	return findGcd(y,x%y);
}
int main()
{
	long n;
	scanf("%ld",&n);
	long a[n];
	for(long i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}
	//cout<<"1"<<endl;
	//cin>>n;
	prime[0]=1;
	prime[1]=1;
	for(long i=2;i<16000001;i++)
	{
		if(!prime[i])
		{
			//cout<<i<<" ";
			for(long j=i;j<16000001;j+=i)
			{
				if(!prime[j])
					prime[j]=i;	
			}
		}
	}
	// for(long i=0;i<20;i++)
	// {
	// 	cout<<prime[i]<<" ";
	// }
	// cout<<endl;
	// for(long i=0;i<n;i++)
	// {
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	// cout<<"done"<<endl;
	long x,y;
	x=a[0];
	for(long i=1;i<n;i++)
	{
		y=a[i];
		x=findGcd(y,x);
	}
	for(long i=0;i<n;i++)
	{
		a[i]/=x;
	}
	//cout<<"yes"<<endl;
	long max=0,temp;
	for(long i=0;i<n;i++)
	{
		while(a[i]>1)
		{
			temp=prime[a[i]];
			freq[temp]++;
			if(freq[temp]>max)
				max=freq[temp];
			while(a[i]%temp==0)
				a[i]/=temp;
		}
	}
	if(max==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	printf("%ld\n",n-max);

}