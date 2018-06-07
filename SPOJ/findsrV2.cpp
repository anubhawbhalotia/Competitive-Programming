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
	int c;
	string s;
	while(cin>>s)
	{
		c=0;
		if(s=="*")
		{
			break;
		}
		long lps[s.length()];
		kmpFindLps(s,lps);
		long temp=lps[s.length()-1];
		for(long i=s.length()-2;i>=0;i--)
		{
			if(lps[i]+1==temp)
			{
				temp=lps[i];
			}
			else
			{
				c=1;
				break;
			}
			if(temp==0)
			{
				c=2;
				break;
			}
		}
		if(c==2)
		{
			if(lps[s.length()-1]>=ceil(s.length()/2) && (s.length()%(s.length()-lps[s.length()-1]))==0)
			{
				cout<<s.length()/(s.length()-lps[s.length()-1])<<endl;
			}
			else
			{
				cout<<"1"<<endl;
			}
		}
		else 
		{
			cout<<"1"<<endl;
		}
		


	}
}