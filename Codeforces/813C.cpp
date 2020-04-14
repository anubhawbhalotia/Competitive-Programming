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
typedef struct node
{
	int p;
	vi c;
}node;
void build(vvi &a, vector<node> &t, int y)
{
	f(i, 0, a[y].size())
	{
		if(a[y][i] != t[y].p)
		{
			t[y].c.pb(a[y][i]);
			t[a[y][i]].p = y;
			build(a, t, a[y][i]);
		}
	}
}
int getMaxDis(vector <node> &t, int y, int &prev)
{
	int z = 0;
	for(auto i : t[y].c)
	{
		if(i == prev)
			continue;
		z = max(z, getMaxDis(t, i, prev) + 1);
	}
	return z;
}
void solution(int tc)
{
	int n, x, u, v;
	cin>>n>>x;
	vvi a(n);
	vector <node> t(n);
	f(i, 0, n - 1)
	{
		cin>>u>>v;
		a[--u].pb(--v);
		a[v].pb(u);
	}
	t[0].p = -1;
	build(a, t, 0);
	int d = 0, z = --x, ans = 0;
	while(z)
	{
		d++;
		z = t[z].p;
	}
	z = x;
	int y = 0, prev = -1, e;
	while((d - y) > y)
	{
		ans = max(ans, d - y + getMaxDis(t, z, prev));
		prev = z;
		z = t[z].p;
		y++;
	}
	cout<<ans*2<<endl;
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
