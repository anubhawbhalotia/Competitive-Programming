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
	int ans;
	int d;
	node()
	{
		d = 0;
		ans = 0;
	}
}node;
int bs(vl &pre, int l, int r, int &n, int &val)
{
	int m;
	while(l < r)
	{
		m = (l + r) / 2;
		if((pre[n] - pre[m]) <= (ll)val)
		{
			r = m;
		}	
		else 
		{
			l = m + 1;
		}
	}
	return l;
}
int traverse(vi &a, vector <node> &t, vi &e, vl &pre, map<pt,int> &w, int x, int l)
{
	int b = 0;
	e[l] = x;
	if(x)
	{
		pre[l] = pre[l - 1] + (ll)w[{x, t[x].p}];
	}
	for(auto i : t[x].c)
	{
		b += traverse(a, t, e, pre, w, i, l + 1);
	}
	t[x].ans += b;
	t[e[bs(pre, 0, l, l, a[x])]].d -= 1;
	b += (t[x].d + 1);
	return b;
}
void solution(int tc)
{
	int n, x, y;
	cin>>n;
	vector <node> t(n);
	vi a(n), e(n);
	map <pt,int> w;
	f(i, 0, n)
	{
		cin>>a[i];
	}
	f(i, 0, n - 1)
	{
		cin>>x>>y;
		w[{--x, i + 1}] = y;
		w[{i + 1, x}] = y;
		t[i + 1].p = x;
		t[x].c.pb(i + 1);
	}
	vector <ll> pre(n, 0);
	traverse(a, t, e, pre, w, 0, 0);
	f(i, 0, n)
	{
		cout<<t[i].ans<<" ";
	}
	cout<<endl;
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
