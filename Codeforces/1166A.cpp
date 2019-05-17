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
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
int main()
{
	int n;
	cin>>n;
	string s;
	int f[300] = {};
	long c[60];
	c[0] =
	c[1] = 0;
	int x = 1;
	f(i,2,58)
	{
		c[i] = c[i-1] + x;
		x++;
	}
	f(i,0,n)
	{
		cin>>s;
		f[s[0]]++;
	}	
	long ans = 0;
	f(i, 97, 123)
	{
		if(f[i] == 0)
			continue;
		ans += c[f[i] / 2] + c[f[i] - (f[i] / 2)];
	}
	cout<<ans<<endl;
} 