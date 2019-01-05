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
long ans[3000000] = {};
int main()
{
	long n;
	cin>>n;
	string s;
	long c;
	multiset <long> m;
	f(i,0,n)
	{
		c = 0;
		long minval=10000000;
		cin>>s;
		f(i,0,s.length())
		{
			c=(s[i]=='(')?c+1:(c-1);
			if(c<minval)
				minval=c;
		}
		//cout<<c<<endl;
		//cout<<c<<" "<<minval<<endl;
		if((minval<0 && c==minval) || minval>=0)
		{
			m.insert(c);
			ans[c+500000]++;
		}
	}
	// for(multiset <long> :: iterator it = m.begin(); it!=m.end(); it++)
	// {
	// 	cout<<*it<<" ";
	// }
	// cout<<endl;
	long val=0;
	for(multiset <long> :: iterator it = m.begin(); it!=m.end(); it++)
	{
		if(*it>0)
			break;
		if(*it==0)
		{
			if(ans[0+500000]>=2)
			{
				ans[0+500000]-=2;
				val++;
			}
		}
		else if(ans[((*it)*-1)+500000]>0)
		{
			ans[*it+500000]--;
			ans[((*it)*-1)+500000]--;
			val++;
		}
	}
	cout<<val<<endl;

}