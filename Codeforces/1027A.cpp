#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>n;
		cin>>s;
		for(i=0;i<n/2;i++)
		{
			if(abs(s[i]-s[n-1-i])==0 || abs(s[i]-s[n-1-i])==2)
				continue;
			else
				break;
		}
		if(i==n/2)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}