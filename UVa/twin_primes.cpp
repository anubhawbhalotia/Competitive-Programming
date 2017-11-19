#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long j,i,b[100010],c[100010],x,n;
	int a[20000101]={};
	a[1]=1;
	for(j=2;j<=10000000;j++)
	{
		if(a[j]==0)
		{
			for(i=j+j;i<=20000100;i+=j)
				a[i]=1;
		}
	}
	a[2]=0;
	i=1;
	x=0;
	while(i<20000090 && x<100001)
	{
		if(a[i]==0 && a[i+2]==0)
		{
			b[x]=i;
			c[x]=i+2;
			x++;
		}
		i++;
	}
	while(cin>>n)
		cout<<"("<<b[n-1]<<", "<<c[n-1]<<")"<<endl;
}