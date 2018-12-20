#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int f[27]={};
		int c=0;
		for(int i=0;i!=s.length();i++)
		{
			f[s[i]-97]++;
		}
		for(int i=0;i<26;i++)
		{
			if(f[i])
				c++;
		}
		if(c==1)
			cout<<"-1"<<endl;
		else
		{
			for(int i=0;i<26;i++)
			{
				for(int j=0;j<f[i];j++)
					cout<<(char)(i+97);
			}
			cout<<endl;
		}
	}
}