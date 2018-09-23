#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,d,m;
	scanf("%d %d",&n,&d);
	scanf("%d",&m);
	int x,y;
	for(long i=0;i<m;i++)
	{
		cin>>x>>y;
		int a=x-y+d;
		int b=x-y-d;
		int c=x+y-d;
		int e=x+y-(2*n)+d;
		//cout<<a<<" "<<b<<" "<<c<<" "<<e<<endl;
		
		if(a>=0 && b<=0 && c>=0 && e<=0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}