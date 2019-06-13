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
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
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
#define fi first
#define se second
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
	int parent;
	vi child;
}node;
typedef long double ld;
int n;
vvi a;
vector <node> tr;
ld ans, prod;
void buildTree()
{
	vi fq(n + 1, 0);
	stack <int> s;
	s.push(1);
	fq[1] = 1;
	while(!s.empty())
	{
		int temp = s.top();
		s.pop();
		f(i, 0, a[temp].size())
		{	
			if(fq[a[temp][i]])
				continue;
			fq[a[temp][i]] = 1;
			s.push(a[temp][i]);
			tr[temp].child.pb(a[temp][i]);
			tr[a[temp][i]].parent = temp;
		}
	}
}
void dfs(int nd, int level, ld prod)
{
	if(tr[nd].child.empty())
	{
		prod *= level;
		ans += prod;
		return ;
	}
	prod /= (ld)tr[nd].child.size();
	f(i, 0, tr[nd].child.size())
		dfs(tr[nd].child[i], level + 1, prod);
}
void solution(int t)
{
	ans = 0;
	cin>>n;
	int u, v;
	a.resize(n + 1);
	tr.resize(n + 1);
	f(i, 0, n - 1)
	{
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}	
	buildTree();
	dfs(1, 0, 1);
	cout<<setprecision(10)<<ans<<endl;
}
void testCase()
{
	int t = 1;
	// cin>>t;
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