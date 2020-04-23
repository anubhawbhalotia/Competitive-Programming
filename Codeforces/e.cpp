#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
const int MOD = 998244353;
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}   
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
void bfs(vvi &a, vi &d, int &n, int x)
{
	queue <int> q;
	q.push(x);
	d[x] = 0;
	vector <bool> flag(n, 0);
	flag[x] = 1;
	int dis = 1;
	while(!q.empty())
	{
		int sz = q.size();
		while(sz--)
		{
			int z = q.front();
			q.pop();
			for(auto i : a[z])
			{
				if(!flag[i])
				{
					flag[i] = 1;
					q.push(i);
					d[i] = dis;
				}
			}
		}
		dis++;
	}
}
ll getPrice(vl &pre, int x, int y, int z)
{
	ll ans;
	ans = ((ll)2 * pre[y]) + (pre[y + x] - pre[y]) + 
		(pre[y + x + z] - pre[x + y]);
	return ans;
}
void solution(int t)
{
	int n, m, x, y, z;
	cin>>n>>m>>x>>y>>z;
	vl p(m), pre(m + 1, 0);
	f(i, 0, m)
	{
		cin>>p[i];
	}
	vvi a(n);
	int u, v;
	f(i, 0, m)
	{
		cin>>u>>v;
		a[--u].pb(--v);
		a[v].pb(u);
	}	
	
	sort(all(p));
	f(i, 1, m + 1)
	{
		pre[i] = pre[i - 1] + p[i - 1];
	}
	vvi d(3, vi(n));
	bfs(a, d[0], n, --x);
	bfs(a, d[1], n, --y);
	bfs(a, d[2], n, --z);
	ll ans = LLONG_MAX;
	f(i, 0, n)
	{
		if(d[0][i] + d[1][i] + d[2][i] <= m)
		{
			ans = min(ans, getPrice(pre, d[0][i], d[1][i], d[2][i]));
		}
	}

	cout<<ans<<endl;
}
void testCase()
{
	int t = 1;
	cin>>t;
	f(i, 0, t)
	{
		solution(i + 1);
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   
