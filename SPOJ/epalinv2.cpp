#include<bits/stdc++.h>
using namespace std;
int kmpFindLps(string s,long lps[])
{
	long len=0;
	long i=1;
	lps[0]=0;
	while(i<s.length())
	{
		if(s[i]==s[len])
		{
			len++;
			lps[i]=len;
			i++;
			continue;
		}
		if(len==0)
		{
			lps[i]=0;
			i++;
			continue;
		}
		len=lps[len-1];
	}
	// for(long i=0;i<s.length();i++)
	// {
	// 	cout<<s[i]<<" ";	
	// }
	// cout<<endl;
	// for(long i=0;i<s.length();i++)
	// {
	// 	cout<<lps[i]<<" ";	
	// }
	return 1;
}
int main()
{
	string s,temp,s1;
	long max;
	while(cin>>s)
	{
		string temp=s;
		reverse(s.begin(),s.end());
		string s1=s+temp;
		long lps[s1.length()];
		kmpFindLps(s1,lps);
		
		if(lps[s1.length()-1]>=(s1.length())/2)
		{
			cout<<temp<<endl;
		}
		else
		{
			string z=temp.substr(0,temp.length()-lps[s1.length()-1]);
			reverse(z.begin(),z.end());
			cout<<temp+z<<endl;
		}	
	}
}