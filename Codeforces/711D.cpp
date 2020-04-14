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
const ll MOD = 1000000007;
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
ll mpow(ll b, ll p)
{
	ll z;
	ll y, ans = 1;
	while(p)
	{
		z = 1;
		y = b;
		while((z * 2) <= p)
		{
			y = (y * y) % MOD;
			z *= 2;
		}
		ans = (ans * y) % MOD;
		p -= z;
	}
	return ans;
}
void dfs(vi &a, vi &b, map <int, int> &c, int x, int &y, int &h)
{
	int i = x;
	stack <int> g;
	while(b[i] == 0)
	{
		g.push(i);
		b[i] = y;
		i = a[i];
	}
	if(b[i] != y)
	{
		while(!g.empty())
		{
			b[g.top()] = b[i];
			g.pop();
		}
	}
	else
	{
		c[y] = 1;
		while(g.top() != i)
		{
			c[y]++;
			g.pop();
		}
		h += c[y];
		y++;
	}
}
void solution(int t)
{
	int n;
	cin>>n;
	vi a(n);
	f(i, 0, n)
	{
		cin>>a[i];
		a[i]--;
	}
	vi b(n, 0);
	map <int,int> c;
	int y = 1, h = 0;
	f(i, 0, n)
	{
		if(!b[i])
		{
			dfs(a, b, c, i, y, h);
		}
	}
	ll ans = 1;
	f(i, 1, y)
	{
		ans = (ans * ((mpow(2, c[i]) - 2)) % MOD) % MOD;
	}
	ans = (ans * (mpow(2, n - h))) % MOD;
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