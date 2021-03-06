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
int n;
vl p(21);
vl a, b;
unordered_map <int, int> y_map, z_map, x_map, y_unmap, z_unmap, x_unmap;
// unordered_set <pair<pair<ll, ll>>, ll> dp;
// vector <vector<vector<long long>>> dp;
ll norm(ll n)
{
	if(n <= 0)
		return 0;
	return n;
}
ll backtrack(int y, int z, int x)
{
    y = norm(y);
    z = norm(z);
    if(y_map.find(y) == y.end())
    {
        y_map[y] = 
    }
	if(x >= n)
	{
		return (y > 0 || z > 0) ? (ll)0 : (ll)1;
	}
	if(y <= 0 && z <= 0)
	{
		return p[n - x];
	}
	if(y <= 0)
	{       
		return ((ll)2 * backtrack(y, z - b[x], x + 1)) + backtrack(y, z, x + 1);
	}
	if(z <= 0)
	{
		return (2 * backtrack(y - a[x], z, x + 1)) + backtrack(y, z, x + 1);
	}
	return backtrack(y, z - b[x], x + 1) +  backtrack(y - a[x], z, x + 1) + 
		backtrack(y - a[x], z - b[x], x + 1);
}                           
ll solution(int t)
{
    y_map.clear();
    z_map.cear();
	int h;
	cin>>n>>h;
	a.resize(n);
	b.resize(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	f(i, 0, n)
	{
		cin>>b[i];
	}
	return backtrack(h, h, 0);
}
void testCase()
{
	int t = 1;
	p[0] = 1;
	f(i, 1, 21)
	{
		p[i] = p[i - 1] * (ll)3;
	}
	cin>>t;
	f(i, 0, t)
	{
		cout<<"Case #"<<i+1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}  
