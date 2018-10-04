#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	scanf("%ld",&n);
	string s;
	cin>>s;
	long e=0,l=0,ans=0;
	for(long i=0;i<n;i++)
	{
		if(s[i]=='8')
			e++;
	}
	//cout<<e<<endl;
	l=n-e;
	while(e>0 && l>=10)
	{
		ans++;
		e--;
		l-=10;
	}
	//cout<<l<<" "<<e<<endl;
	if(e!=0)
	{
		ans+=(l+e)/11;
	}
	cout<<ans<<endl;
}