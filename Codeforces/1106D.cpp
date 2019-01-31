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
	long n,m;
	cin>>n>>m;
	vector <long> s[n+1],ans;
	long u[m+1],v[m+1];
	int fr[100001]={};
	f(i,0,m)
	{
		scanf("%ld %ld",&u[i],&v[i]);
		s[u[i]].push_back(v[i]);
		s[v[i]].push_back(u[i]);
	}	
	set <long> d;
	d.insert(1);
	while(d.size())
	{
		while(fr[*d.begin()]==1)
		{
			ans.pb(*d.begin());
			d.erase(d.begin());
		}
		long small=*d.begin();
		fr[small]=1;
		ans.pb(small);
		d.erase(d.begin());
		f(i,0,s[small].size())
		{
			if(fr[s[small][i]]==0)
				d.insert(s[small][i]);
		}
	}
	f(i,0,n)
		printf("%ld ",ans[i]);
}
