#include<bits/stdc++.h>
using namespace std;
int main()
{
	long p[35]={};
	long long l,r,mid;
	string inp, intinp;
	p[0]=0;
	p[1]=1;
	for(int i=2;i<=31;i++)
	{
		p[i]=2*p[i-1];
	}
	while(1)
	{
		cin>>inp;
		if(inp=="end" || inp=="mistake")
			break;
		for(int i=0;i<31;i++)
		{
			cout<<"? "<<p[i]<<" "<<p[i+1]<<endl;
			cin>>intinp;
			if(intinp=="x")
			{
				l=p[i];
				r=p[i+1];
				break;
			}
		}
		while(r-l>1)
		{
			mid = (l+r)/2;
			cout<<"? "<<l<<" "<<mid<<endl;
			cin>>intinp;
			if(intinp=="x")
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		cout<<"! "<<r<<endl;
	}
}
