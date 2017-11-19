#include<bits/stdc++.h>
using namespace std;
long coins(long n,long a[])
{
	if(n==1 || n==0)
	{
		return n;
	}
	long x,y,z;
	if(!(a[(int)n/2]))
	{
		x=coins(n/2,a);
	}
	else
	{
		x=a[n/2];
	}
	if(!(a[(int)n/3]))
	{
		y=coins(n/3,a);
	}
	else
	{
		y=a[n/3];
	}
	if(!(a[(int)n/4]))
	{
		z=coins(n/4,a);
	}
	else
	{
		z=a[n/4];
	}
	if((x+y+z)>n)
	{
		a[n]=x+y+z;
	}
	else
	{
		a[n]=n;
	}
	return a[n];
}
int main()
{
	long n;
	long a[1000000000]={};
	a[0]=0;
	a[1]=1;
	while(scanf("%ld",&n)!=EOF)
	{
		cout<<coins(n,a)<<endl;
	}
}