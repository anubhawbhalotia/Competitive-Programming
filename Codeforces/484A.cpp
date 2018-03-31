#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	long long l,r,x,p,y;
	scanf("%ld",&n);
	while(n--)
	{
		cin>>l;
		cin>>r;
		x=1;
		p=1;
		while(x<=r)
		{
			p=p*2;
			x=x+p;
		}
		//cout<<"x="<<x<<" p"<<p<<endl;
		if((x-p)>=l)
		{
			cout<<x-p<<endl;
			continue;
		}
		y=x;
		while(1)
		{
			if(y>r)
			{
				p/=2;
				y-=p;
			}
			else if(y<l)
			{
				y+=p;
				p=p/2;
				y-=p;
			}
			else
			{
				break;
			}
		}
		cout<<y<<endl;

	}
}