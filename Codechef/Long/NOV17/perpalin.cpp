#include <bits/stdc++.h>
using namespace std;
int main()
{
	long t; 
	cin>>t;
	while(t--)
	{
		long n,p,c,i;
		cin>>n>>p;
		string s,g;
		if(p==1 || p==2)
		{
			cout<<"impossible\n";
			continue;
		}
		c=n/p;
		s="a";
		for(i=1;i<p-1;i++)
		{
			s+="b";
		}
		s+="a";
		g=s;
		for(i=0;i<c-1;i++)
		{
			g+=s;
		}
		cout<<g<<endl;
	}
}
