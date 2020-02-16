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
#define F first
#define S second
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

typedef struct node
{
	int p, d, z;
	vector <int> c;
}node;
vector <node> graph;
vvi t;
vi v, f, p;
int n;
class segTree
{
	vi a;
public:
	segTree()
	{
		a.resize(1000000, 0);
	}
	int build(vi &b, int nd = 0, int l = 0, int r = p.size() - 1)
	{
		if(l == r)
		{
			a[nd] = b[l];
			return a[nd]; 
		}
		a[nd] = min(build(b, nd*2 + 1, l, (l + r) / 2), 
			build(b, nd*2 + 2, (l + r) / 2 + 1, r));
		return a[nd];
	}
	int query(int lo, int hi, int nd = 0, int l = 0, int r = p.size() - 1)
	{
		if(lo <= l && hi >= r)
			return a[nd];
		if(lo > r || hi < l)
			return INT_MAX;
		return min(query(lo, hi, nd*2 + 1,  l, (l + r) / 2), 
			query(lo, hi, nd*2+2, (l + r) / 2 + 1, r));
	}
};
segTree s;
void buildTree(int x, int depth)
{
	graph[x].d = depth;
	f(i, 0, t[x].size())
	{
		if(!v[t[x][i]])
		{
			v[t[x][i]] = 1;
			graph[x].c.pb(t[x][i]);
			graph[t[x][i]].p = x;
			buildTree(t[x][i], depth + 1);
		}
	}
}
unordered_map <int, int> u, z;
void bfsTree()
{
	queue <int> q;
	q.push(1);
	int x = 1;
	u[1] = x;
	z[x++] = 1;
	while(!q.empty())
	{
		int sz = q.size();
		f(i, 0, sz)
		{
			int temp = q.front();
			q.pop();
			f(j, 0, graph[temp].c.size())
			{
				q.push(graph[temp].c[j]);
				u[graph[temp].c[j]] = x;
				z[x++] = graph[temp].c[j];
			}
		}
	}
}
void dfs(int nd)
{
	p.pb(u[nd]);
	f[u[nd]] = p.size() - 1;
	f(i, 0, graph[nd].c.size())
	{
		dfs(graph[nd].c[i]);
		p.pb(u[nd]);
	}
}
int lca(int x, int y)
{
	int a = f[u[x]], b = f[u[y]];
	if(a > b)
		swap(a, b);
	return z[s.query(a, b)];
}
int lcaPreprocessing()
{
	f.resize(n + 1, -1);
	bfsTree();
	dfs(1);
	s.build(p);
}
int pathLength(int a, int b)
{
	return graph[a].d + graph[b].d - (2*graph[lca(a, b)].d);
}
bool processQuery()
{
	int x, y, a, b, k, l;
	cin>>x>>y>>a>>b>>k;
	l = pathLength(a, b);
	if(l <= k)
	{
		if((l % 2 == 0 && k % 2 == 0) || (l % 2 == 1 && k % 2 == 1))
			return 1;
	}
	l = pathLength(a, x) + 1 + pathLength(b, y);
	if(l <= k)
	{
		if((l % 2 == 0 && k % 2 == 0) || (l % 2 == 1 && k % 2 == 1))
			return 1;
	}
	l = pathLength(a, y) + 1 + pathLength(b, x);
	if(l <= k)
	{
		if((l % 2 == 0 && k % 2 == 0) || (l % 2 == 1 && k % 2 == 1))
			return 1;
	}
	return 0;
}
void solution()
{
	int x, y, q;
	cin>>n;
	t.resize(n + 1);
	f(i, 0, n - 1)
	{
		cin>>x>>y;
		t[x].pb(y);
		t[y].pb(x);
	}
	v.resize(n + 1, 0);
	v[1] = 1;
	graph.resize(n + 1);
	graph[1].p = 0;
	buildTree(1, 0);
	lcaPreprocessing();
	cin>>q;
	f(i, 0, q)
	{
		if(processQuery())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		solution();
	}
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	testCase();
}   