#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,k,max,max1,i;
	cin>>n>>k;
	long a[n],b[n],c[n];
	max=-1000000001;
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	if(k==0)
	{
		for(i=0;i<n;i++)
		{
			printf("%ld ",a[i]);
		}
		return 0;
	}
	max1=-1000000001;
	for(i=0;i<n;i++)
	{
		b[i]=max-a[i];
		if(b[i]>max1)
		{
			max1=b[i];
		}
	}
	for(i=0;i<n;i++)
	{
		c[i]=max1-b[i];
	}
	if(k%2==0)
	{
		for(i=0;i<n;i++)
		{
			printf("%ld ",c[i]);
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("%ld ",b[i]);
		}
	}
}