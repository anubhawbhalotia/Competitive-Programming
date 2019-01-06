#include<bits/stdc++.h>
using namespace std;
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
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
int main()
{
	string s,ans="";
	cin>>s;
	int k;
	cin>>k;
	int l=s.length();
	int sf=0,cc=0;
	f(i,0,s.length())
	{
		if(s[i]=='*')
			sf++;
		else if(s[i]=='?')
			cc++;
	}
	//cout<<sf<<" "<<cc<<" "<<l<<endl;	
	if((k<l-(2*(sf+cc)))|| (sf==0 && k>l-cc))
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(k<=l-sf-cc)
	{
		int diff=l-sf-cc-k;
		f(i,0,s.length())
		{
			if(s[i]=='*' || s[i]=='?')
				continue;
			if(diff)
			{
				if(s[i+1] == '*' || s[i+1]=='?')
					diff--;
				else
					ans+=s[i];
			}
			else
				ans+=s[i];
		}
	}
	else
	{
		int diff = k - (l-sf-cc);
		f(i,0,s.length())
		{
			if(s[i]=='*' || s[i]=='?')
				continue;
			ans+=s[i];
			if(diff)
			{
				if(s[i+1]=='*')
				{
					while(diff)
					{
						ans+=s[i];
						diff--;
					}
				}
			}
		}
	}
	cout<<ans<<endl;



}