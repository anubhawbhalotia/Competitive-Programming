#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
#define p(i) cout<<i<<endl;
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
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
	long n, m, k, inp;
	cin>>n>>m>>k;
	vector <pll> v;
	vl f;
	f(i,0,n)
	{
		scanf("%ld",&inp);
		v.pb(mp(inp, i));
	}
	sort(all(v));
	ll s = 0;
	long l = v.size() - m*k;
	fr(i,v.size()-1,(long)v.size() - (long)m*(long)k)
	{
		s += (ll)v[i].fi;
		f.pb(v[i].se);
	}
	sort(all(f));
	cout<<s<<endl;
	for(long i=m-1; i!=f.size()-1; i+=m)
		cout<<f[i]+1<<" ";
	cout<<endl;
} 