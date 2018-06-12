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
	for(long i=0;i<s.length();i++)
	{
		cout<<s[i]<<" ";	
	}
	cout<<endl;
	for(long i=0;i<s.length();i++)
	{
		cout<<lps[i]<<" ";	
	}
	return 1;
}
int main()
{
	int c;
	long ans,n,t;
	string s;
	cin>>t;
	int x=1;
	while(t--)
	{
		cin>>n;
		cin>>s;
		c=0;
		long lps[s.length()];
		kmpFindLps(s,lps);
		//cout<<"\n"<<s.length()<<endl;
		cout<<"Test case #"<<x<<endl;
		x++;
		for(long ii=1;ii<s.length();ii++)
		{
			long temp=lps[ii];
			for(long i=ii-1;i>=0;i--)
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
				if(lps[ii]>=ceil((ii+1)/2) && ((ii+1)%((ii+1)-lps[ii]))==0)
				{
						ans=(ii+1)/((ii+1)-lps[ii]);
				}
				else
				{
					ans=0;
				}
			}
			else 
			{
				ans=0;
			}
			if(ans)
			{
				cout<<ii+1<<" "<<ans<<endl;
			}
			
		}
		cout<<endl;


	}
	
}