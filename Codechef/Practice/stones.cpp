#include<bits/stdc++.h>
using namespace std;
int main()
{
	string j,s;
	int i,t;
	cin>>t;
	while(t--)
	{
		int c[150]={},count=0;
		cin>>j;
		for(i=0;i!=j.length();i++)
		{
			c[j[i]]++;
		}
		cin>>s;
		for(i=0;i!=s.length();i++)
		{
			if(c[s[i]])
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
}