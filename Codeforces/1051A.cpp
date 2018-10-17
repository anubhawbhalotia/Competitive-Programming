#include<bits/stdc++.h>
using namespace std;
#define l  long
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhalotia 
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define mod 10e9 + 7
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int main()
{
	int t;
	scanf("%d",&t);
	S s;
	while(t--)
	{
	cin>>s;
	int lower=0,upper=0,digit=0;
	int c[3]={};
	int d[3]={};
	for(int i=0;i!=s.length();i++)
	{
		if(s[i]>=97 && s[i]<=122)
		{
			c[0]=i;
			lower++;
			d[0]=1;
		}
		else if(s[i]>=65 && s[i]<=90)
		{
			c[1]=i;
			upper++;
			d[1]=1;
		}
		else if(s[i]>=48 && s[i]<=57)
		{
			c[2]=i;
			digit++;
			d[2]=1;
		}
	}
	if(d[0]+d[1]+d[2]==1)
	{
		if(d[0])
		{
			s[0]='A';
			s[1]='1';
		}
		else if(d[1])
		{
			s[0]='a';
			s[1]='1';
		}
		else
		{
			s[0]='a';
			s[1]='A';
		}
	}
	else if(d[0]+d[1]+d[2]==2)
	{
		if(!d[0])
		{
			if(upper>digit)
				s[c[1]]='a';
			else
				s[c[2]]='a';
		}
		else if(!d[1])
		{
			if(lower>digit)
				s[c[0]]='A';
			else
				s[c[2]]='A';
		}
		else
		{
			if(lower>upper)
				s[c[0]]='1';
			else
				s[c[1]]='1';
		}
	}
	cout<<s<<endl;
	}	
}