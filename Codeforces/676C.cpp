#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,k,start,end,maxa,maxb,a,i;
	string s;
	cin>>n>>k;
	cin>>s;
	start=0;
	end=-1;
	maxb=0;
	maxa=0;
	a=k;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='b' && a==0)
		{
			if(s[start]=='b')
			{
				a++;
			}
			start++;
			i--;
			continue;
		}
		if(s[i]=='b')
		{
			a--;
		}
		end=i;
		if(end-start+1>maxb)
		{
			maxb=end-start+1;
		}

	}
	a=k;
	start=0;
	end=-1;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='a' && a==0)
		{
			if(s[start]=='a')
			{
				a++;
			}
			start++;
			i--;
			continue;
		}
		if(s[i]=='a')
		{
			a--;
		}
		end=i;
		if(end-start+1>maxa)
		{
			maxa=end-start+1;
		}

	}
	cout<<max(maxa,maxb);
}