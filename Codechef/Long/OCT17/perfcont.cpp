#include<iostream>
using namespace std;
int main()
{
	int t,n,i;
	long p,a;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		int c=0,d=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a>=(p/2))
			{
				c++;
				continue;
			}
			if(a<=(p/10))
			{
				d++;
				continue;
			}
		}
		if(c==1 && d==2)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
}