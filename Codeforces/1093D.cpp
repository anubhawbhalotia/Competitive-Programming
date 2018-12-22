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
#define fr(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
ll p[300006];
long a[3];
int nw;
void dfs(long node, int col,int c[],vl e[])
{
	if(c[node])
	{
		if(c[node]!=col)
			nw=1;
		return ;
	}
	if(nw)
		return ;
	c[node]=col;
	a[col]++;
	f(j,0,e[node].size())
	{
		dfs(e[node][j], 2-(col/2), c, e);
		if(nw)
			break;
	}
	return ;
}
int main()
{
	long t;
	cin>>t;
	p[0] = 1;
	f(i,1,300005)
		p[i] = (p[i-1]*2)%mod;
	while(t--)
	{
		long n,m,u,v;
		cin>>n>>m;
		vl e[n+1];
		f(i,0,m)
		{
			cin>>u>>v;
			u--;
			v--;
			e[u].pb(v);
			e[v].pb(u);
		}
		int c[n+1];
		memset(c,0,sizeof(c));
		ll ans = 1;
		nw=0;
		f(i,0,n)
		{
			if(c[i])
				continue;
			a[1] = a[2] = 0;
			dfs(i,1,c,e);
			if(nw)
				break;
			ans = (ans*(p[a[1]]+p[a[2]])) % mod;
		}
		if(nw)
			cout<<"0"<<endl;
		else
			cout<<ans<<endl;
	}	
} 