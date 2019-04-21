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
void build(long a[],  long tree[], long pref[], long node, long l, long r)
{
	if(l==r)
	{
		tree[node] = a[l];
		pref[node] = a[l];
		return;
	}
	long mid = (l+r)/2;
	build(a, tree, pref, node*2 + 1, l, mid);
	build(a, tree, pref, node*2 + 2, mid+1, r);
	tree[node] = tree[node*2 + 1] + tree[node*2 + 2];
	pref[node] = max(pref[node*2+1],(tree[node*2+1] + pref[node*2+2]));
	pref[node] = max(pref[node], tree[node]);
}
void update(long tree[], long pref[], long node, long l, long r, long index, long val)
{
	if(index<l || index>r)
		return ;
	if(l==r)
	{
		tree[node] = val;
		pref[node] = val;
		return;
	}
	long mid = (l+r)/2;
	update(tree, pref, node*2 + 1, l, mid, index, val);
	update(tree, pref, node*2 + 2, mid + 1, r, index, val);
	tree[node] = tree[node*2 + 1] + tree[node*2 + 2];
	pref[node] = max(pref[node*2+1],(tree[node*2+1] + pref[node*2+2]));
	pref[node] = max(pref[node], tree[node]);
}
int main()
{
	int t;
	cin>>t;
	f(k,1,t+1)
	{
		long n, m=0, s;
		cin>>n>>s;
		set <long> d[100001];
		long a[n+1];
		long tree[n*5], pref[n*5] = {};
		long f[100001] = {};  //Strores frequency of each type
		long g[n+1];   //stored  modified version of aray a after l moves right by 1
		long h = 0;
 		f(i,0,n)
		{
			cin>>a[i];
			f[a[i]]++;
			if(f[a[i]] <= s)
				g[i] = 1;
			else if(f[a[i]] == s+1)
			{
				g[i] = -1 * s;
				d[a[i]].insert(i);
			}
			else
			{
				g[i] = 0;
				d[a[i]].insert(i);
			}
			h = max(h,a[i]);
		}
		build(g, tree, pref, 0, 0, n-1);
		m = pref[0];
		f(i,0,n-1)
		{
			update(tree, pref, 0, 0, n-1, i, 0);
			if(!d[a[i]].empty())
			{
				update(tree, pref, 0, 0, n-1, *(d[a[i]].begin()), 1);
				d[a[i]].erase(d[a[i]].begin());
			}
			if(!d[a[i]].empty())
				update(tree, pref, 0, 0, n-1, *(d[a[i]].begin()), -1 * s);
			m = max(m, pref[0]);
		}
		cout<<"Case #"<<k<<": "<<m<<endl;
	}	
} 