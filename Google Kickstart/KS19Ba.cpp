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
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
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
	int t;
	cin>>t;
	f(k,0,t)
	{
		long n,q,ans = 0,l,r;
		string s;
		cin>>n>>q;
		cin>>s;
		long p[10001][26] = {}, f[26] = {};
		p[0][s[0] - 65] = 1;
		f(i,1,n)
		{
			f(j,0,26)
				p[i][j] = p[i-1][j];
			p[i][s[i] - 65] += 1;
		}
		f(i,0,q)
		{
			cin>>l>>r;
			l--;
			r--;
			if(l==0)
			{
				f(j,0,26)
					f[j] = p[r][j];
			}
			else
			{
				f(j,0,26)
					f[j] = p[r][j] - p[l-1][j];
			}
			int c = 0;
			f(j,0,26)
			{
				if(f[j] % 2 == 1)
					c++;
			}
			if(c <= 1)
				ans++;
		}
		cout<<"Case #"<<k+1<<": "<<ans<<endl;
	}	
} 