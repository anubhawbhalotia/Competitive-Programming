#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long l,len,ans,count=0;
	string pat,s,ls;
	while(scanf("%lld",&l)!=EOF)
	{
		ans=0;
		cin>>pat;
		cin>>s;
		long long lps[pat.length()],i;
		len=0;
		i=1;
		lps[0]=0;
		while(i<pat.length())
		{
			if(pat[i]==pat[len])
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
		// for(i=0;i<l;i++)
		// {
		// 	cout<<s[i]<<" ";
		// }
		// cout<<endl;
		// for(i=0;i<l;i++)
		// {
		// 	cout<<lps[i]<<" ";
		// }
		// cout<<endl;
		long long c=0;
		if(count==0)
		{
			count++;
		}
		else
		{
			cout<<endl;
		}
		i=0;
		while(i<s.length())
		{
			if(c==pat.length())
			{
				cout<<i-c<<endl;
				ans++;
				c=lps[pat.length()-1];
			}
			if(pat[c]==s[i])
			{
				c++;
				i++;
				continue;
			}
			if(c!=0)
			{
				c=lps[c-1];
			}
			else
			{
				i++;
			}
		}
		if(c==pat.length())
		{
			cout<<i-c<<endl;
			ans++;
			c=lps[pat.length()-1];
		}	
		// if(s[s.length()]==EOF)
		// {
		// 	break;
		// }
		// cin>>ls;
		// if(ls=="EOF")
		// {
		// 	break;
		// }
		// l=ls[0]-48;
		// for(i=1;i<ls.length();i++)
		// {
		// 	l=(l*10)+(ls[i]-48);
		// }
	}
}