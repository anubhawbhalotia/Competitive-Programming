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
	long n, r, b, nd, m = 0;
	string s, ans = "";
	cin>>n;
	cin>>s;
	//Finding nesting depth of s
	f(i, 0, n)
	{
		nd = (s[i] == '(') ? (nd + 1) : (nd - 1);
		m = max(nd, m);
	}	
	r = m / 2;
	b = m - r;
	stack <char> k;
	f(i, 0, n)
	{
		if(s[i] == '(')
		{
			if(r)
			{
				k.push('0');
				ans += '0';
				r--;
			}
			else
			{
				k.push('1');
				ans += '1';
				b--;
			}
		}
		else
		{
			if(k.top() == '0')
				r++;
			else
				b++;
			ans += k.top();
			k.pop();
		}
	}
	cout<<ans<<endl;

} 