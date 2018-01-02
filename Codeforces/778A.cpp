#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
long a[26]={},pp[200001]={},c=0;
string p,t;
set <long> s[26];
int check()
{
	long v,i;
	set <long> ::iterator it;
	if(c<p.length())
	{
		return 0;
	}
	v=-1;
	for(i=0;i!=p.length();i++)
	{
		it=s[p[i]-97].upper_bound(v);
		if(it==s[p[i]-97].end())
		{
			break;
		}
		v=*it;
	}
	if(i==p.length())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
long bs(long curr,long start,long end)
{
	long i,mid;
	if(start==end)
	{
		return start;
	}
	mid=ceil((start+end)/2.0);
	if(mid>=curr)
	{
		for(i=start+1;i<=mid;i++)
		{
			if(a[t[pp[i]]-97])
			{
				s[t[pp[i]]-97].erase(pp[i]);
				c--;
			}
		}
	}
	else if(mid<curr)
	{
		for(i=end+1;i>mid;i--)
		{
			if(a[t[pp[i]]-97])
			{
				s[t[pp[i]]-97].insert(pp[i]);
				c++;
			}
		}
	}
	if(check())
	{
		return bs(mid,mid,end);
	}
	else
	{
		return bs(mid,start,mid-1);
	}
}
int main()
{
	cin>>t>>p;
	long i;
	for(i=1;i!=t.length()+1;i++)
	{
		cin>>pp[i];
		pp[i]--;
	}
	for(i=0;i!=p.length();i++)
	{
		a[p[i]-97]=1;
	}
	for(i=0;i!=t.length();i++)
	{
		if(a[t[i]-97])
		{
			s[t[i]-97].insert(i);
			c++;
		}
	}
	cout<<bs(0,0,t.length())<<endl;
}

		