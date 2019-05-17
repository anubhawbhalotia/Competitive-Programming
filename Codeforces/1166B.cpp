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
	int k;
	cin>>k;
	int s = (int)sqrt(k);
	int n = 0, m;
	string v = "aeiou";
	fe(i, 5, s)
	{
		if(k % i == 0)
		{
			n = i;
			m = k / i;
			break;
		}
	}	
	if(n == 0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	string ans = "";
	f(i, 0, n)
	{
		int c = i % 5;
		f(j, c, c + m)
			ans += v[j % 5];
	}
	cout<<ans<<endl;
} 