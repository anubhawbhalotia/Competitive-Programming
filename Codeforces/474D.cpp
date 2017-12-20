#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
	long long t,k,i,a[100001],b[100001],c,d;
	cin>>t>>k;
	a[0]=0;
	b[0]=0;
	for(i=1;i<k;i++)
	{
		a[i]=1;
		b[i]=b[i-1]+a[i];
	}
	a[k]=2;
	b[k]=b[k-1]+a[k];
	for(i=k+1;i<=100000;i++)
	{
		a[i]=((a[i-1]%M)+(a[i-k]%M))%M;
		b[i]=(b[i-1])+(a[i]);
	}
	/*for(i=1;i<=20;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(i=1;i<=20;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;*/

	while(t--)
	{
		cin>>c>>d;
		cout<<(b[d]-b[c-1])%M<<endl;
	}
}