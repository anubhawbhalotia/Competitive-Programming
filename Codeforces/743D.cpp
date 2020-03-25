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
const ll M = -10000000000000000;
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
ptl trav(vvi &b, vector<bool> &g, vi &a, ll &ans, int x)
{
	g[x] = 1;
	ll s = a[x];
	ll m1 = M, m2 = M;
	ptl temp;
	for(auto i : b[x])
	{
		if(!g[i])
		{
			g[i] = 1;
			temp = trav(b, g, a, ans, i);
			s += temp.y;
			if(temp.x >= m1)
			{
				m2 = m1;
				m1 = temp.x;
			}
			else if(temp.x >= m2)
			{
				m2 = temp.x;
			}
		}
	}
	if(m2 != M)
	{
		ans = max(ans, m1 + m2);
	}
	// cout<<"x = "<<x<<" m1 = "<<m1<<" m2 = "<<m2<<" "<<max(s, m1)<<" "<<s<<endl;
	return {max(s, m1), s};
}
void solution(int t)
{
	int n;
	cin>>n;
	vi a(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	vvi b(n);
	vector <bool> g(n, 0);
	int u, v;
	f(i, 0, n - 1)
	{
		cin>>u>>v;
		b[--u].pb(--v);
		b[v].pb(u);
	}
	ll ans = M * 10;
	ptl temp = trav(b, g, a, ans, 0);
	if(ans == M * 10)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		cout<<ans<<endl;
	}
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