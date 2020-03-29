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
void dp(set <vector<int>> &DP, vi &x, vi &y, vi &a, vvi &b, int &ans,
	int r, int c, int d, int e)
{
	if(d == (int)a.size())
		return ;
	if(DP.find({r, c, d, e}) != DP.end())
		return ;
	int z = a[d];
	DP.insert({r, c, d, e});
	while(z--)
	{
		if(b[r][c] == 0)
			ans++;
		b[r][c] = 1;
		if(z)
		{
			r += x[e];
			c += y[e];
		}
	}
	int d1 = (e + 8 - 1) % 8;
	int d2 = (e + 8 + 1) % 8;
	dp(DP, x, y, a, b, ans,
		r + x[d1], c + y[d1], d + 1, d1);
	dp(DP, x, y, a, b, ans,
		r + x[d2], c + y[d2], d + 1, d2);
}
void solution(int t)
{
	int n;
	cin>>n;
	vi a(n);
	f(i, 0, n)
		cin>>a[i];
	vi x = {-1, -1, 0, 1, 1, 1, 0, -1};
	vi y = {0, 1, 1, 1, 0, -1, -1, -1};
	set <vector<int>> DP;
	vvi b(400, vi(400, 0));
	int ans = 0;
	dp(DP, x, y, a, b, ans, 160, 160, 0, 0);
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