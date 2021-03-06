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
class segTree
{
	vi t;
	int n;
public:
	segTree(int z)
	{
		t.resize(2000000, 0);
		n = z;
	}
	void inst(int val, int x, int node = 0, int l = 0, int r = -1)
	{
		if(r == -1)
		{
			r = n - 1;
		}
		if(x < l || x > r)
			return ;
		if(l == r)
		{
			t[node] = val;
			return;
		}
		inst(val, x, node*2+1, l, (l + r) / 2);
		inst(val, x, node*2+2, (l + r) / 2 + 1, r);
		t[node] = max(t[node*2+1], t[node*2+2]);
	}
	int query(int st, int en, int node = 0, int l = 0, int r = -1)
	{
		if(r == -1)
			r = n - 1;
		if(st > r || en < l)
			return 0;
		if(l >= st && r <= en)
		{
			return t[node];
		}
		return max(query(st, en, node*2+1, l, (l + r) / 2), query(st, en, node*2+2, (l + r) / 2 + 1, r));
	}
};
int bs(vector<pt> &b, int val)
{
	int l = 0, r = b.size() - 1;
	while(l < r)
	{
		int m = (l + r) / 2 + 1;
		if(b[m].x < val)
		{
			l = m;
		}
		else
		{
			r = m - 1;
		}
	}
	if(b[l].x < val)
		return l;
	else
		return -1;
}
void solution(int t)
{
	int n;
	cin>>n;
	
	vector<pt> a(n), b;
	f(i, 0, n)
	{
		cin>>a[i].x>>a[i].y;
	}
	sort(all(a));
	
	f(i, 0, n)
	{
		b.pb({a[i].y, i});
	}
	sort(all(b));

	map <pt, int> m;
	f(i, 0, n)
	{
		m[{b[i].x, b[i].y}] = i;
	}
	segTree tree(n);
	int z, ans = 0, g;
	f(i, 0, n)
	{
		z = bs(b, a[i].x);
		g = tree.query(0, z) + 1;
		ans = max(ans, g);
		tree.inst(g, m[{a[i].y, i}]);
	}
	cout<<ans<<endl;
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
