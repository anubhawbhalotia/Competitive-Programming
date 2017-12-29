#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,x,i,f,g;
	cin>>n>>a>>b;
	x=(a+b)/n;
	for(i=x;i>=1;i--)
	{
		f=a/i;
		g=b/i;
		if((f+g)>=n && f!=0 && g!=0)
		{
			cout<<i;
			break;
		}
	}
}