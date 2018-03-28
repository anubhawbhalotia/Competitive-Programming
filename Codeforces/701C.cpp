#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	long n,count=0,c=0,start,end,min;
	long f[200]={},g[200]={};
	cin>>n;
	cin>>s;
	for(long i=0;i<s.length();i++)
	{
		if(f[s[i]]==0)
		{
			count++;
		}
		f[s[i]]++;
	}
	//cout<<count<<endl;
	start=0;
	end=-1;
	min=200000;
	for(long i=0;i<s.length();i++)
	{
		if(c==count)
		{
			if(end-start+1<min)
			{
				min=end-start+1;
			}
		}
		if(c==count && end>start)
		{
			if(g[s[start]]==1)
			{
				c--;
			}
			g[s[start]]--;
			start++;
			i--;
			continue;
		}
		end=i;
		if(g[s[i]]==0)
		{
			c++;
			if(c==count)
			{
				if((end-start+1)<min)
				{
					min=end-start+1;
				}
			}
		}
		g[s[i]]++;
		
	}
	while(c==count)
	{
		if(end-start+1<min)
		{
			min=end-start+1;
		}
		if(g[s[start]]==1)
		{
			c--;
			break;
		}
		g[s[start]]--;
		start++;
		
	}
	cout<<min;

}

