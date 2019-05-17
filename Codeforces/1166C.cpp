#include<bits/stdc++.h>
using namespace std;
#define fi first
#define	se second
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define beg(x) x.begin()
#define en(x) x.end()
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
const ll INF = 1e18;
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef set<pl> spl;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
typedef multiset<pl> mspll;
int main()
{
	long n, c;
	cin>>n;
	msl m;
	f(i,0,n)
	{
		cin>>c;
		if(c<0)
			c = c*-1;
		m.insert(c);
	}
	spl a;
	long x = 0;
	for(msl :: iterator it = m.begin(); it != m.end(); it++)
		a.insert(mp(*it, x++));
	ll ans = 0;
	for(spl :: iterator it = a.begin(); it != a.end(); it++)
	{
		spl :: iterator l = a.ub(mp((it->fi)*2, n + 1));
		if(l == a.end())
			ans += (ll)(n-1) - (ll)it->se;
		else
			ans += (ll)l->se - (ll)it->se - 1;
	}
	cout<<ans<<endl;
} 