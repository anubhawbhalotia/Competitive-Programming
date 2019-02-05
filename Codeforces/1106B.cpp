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
vector <long> v[100001];
long f[1000001]={};
long a[100001]={};
long c[100001]={};
long t[100001]={};
long d[100001]={};
int main()
{
	long n,m;
	scanf("%ld %ld",&n,&m);
	f(i,0,n)
		scanf("%ld",&a[i]);
	set <long> e;
	long distinctCost=1;
	f(i,0,n)
	{
		scanf("%ld",&c[i]);
		if(f[c[i]]==0)
		{
			e.insert(c[i]);
			f[c[i]]=distinctCost;
			distinctCost++;
		}
		v[f[c[i]]].pb(i);
	}
	ll cost;
	long i;
	set <long> :: iterator it = e.begin();
	f(j,0,m)
	{
		scanf("%ld %ld", &t[j],&d[j]);
		t[j]--;
		cost=0;
		if(a[t[j]] >= d[j])
		{
			cost+=((ll)c[t[j]]*(ll)d[j]);
			a[t[j]] -= d[j];
		}
		else
		{
			cost+=((ll)a[t[j]]*(ll)c[t[j]]);
			d[j]-=a[t[j]];
			a[t[j]]=0;
			while(d[j])
			{
				while(it!=e.end())
				{
					if(v[f[*it]].size()==0)
					{
						it++;
						continue;
					}
					i=0;
					while(i!=v[f[*it]].size())
					{
						if(a[v[f[*it]][i]]!=0)
							break;
						i++;
					}
					if(i==v[f[*it]].size())
						it++;
					else
						break;
				}
				if(it==e.end())
					break;
				if(a[v[f[*it]][i]] >= d[j])
				{
					cost+=((ll)c[v[f[*it]][i]] * (ll)d[j]);
					a[v[f[*it]][i]] -= d[j];
					d[j]=0;
				}
				else
				{
					cost+=((ll)c[v[f[*it]][i]] * (ll)a[v[f[*it]][i]]);
					d[j] -= a[v[f[*it]][i]];
					a[v[f[*it]][i]]=0;
				}
			}
			if(d[j])
				cost=0;
		}
		cout<<cost<<endl;
	}
}