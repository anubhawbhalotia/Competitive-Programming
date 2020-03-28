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
int dp(vvi &DP, string &s, int &n, int x, int k)
{
	if(k == 2)
	{
		if(DP[0][x] != -1)
			return DP[0][x];
		if(x <= n - 2 && s.substr(x - 2, 2) != s.substr(x, 2))
		{
			DP[0][x] = max(DP[0][x], dp(DP, s, n, x + 2, 2));
		}
		if(x <= n - 3)
		{
			DP[0][x] = max(DP[0][x], dp(DP, s, n, x + 3, 3));
		}
		if(x == n)
		{
			DP[0][x] = 1;
		}
		if(x == n - 1)
		{
			DP[0][x] = 0;
		}
		return DP[0][x];
	}
	else
	{
		if(DP[1][x] != -1)
			return DP[1][x];
		if(x <= n - 3 && s.substr(x - 3, 3) != s.substr(x, 3))
		{
			DP[1][x] = max(DP[1][x], dp(DP, s, n, x + 3, 3));
		}
		if(x <= n - 2)
		{
			DP[1][x] = max(DP[1][x], dp(DP, s, n, x + 2, 2));	
		}
		if(x == n)
		{
			DP[1][x] = 1;
		}
		if(x == n - 1)
		{
			DP[1][x] = 0;
		}
		return DP[1][x];
	}
	return 0;
}
void solution(int t)
{
	string s;
	cin>>s;
	int n = s.length();
	vvi DP(2, vi(n + 3, -1));
	set<string> a;
	fe(i, 7, n)
	{
		if(DP[0][i] == -1)
			dp(DP, s, n, i, 2);
		if(DP[0][i] == 1)
			a.insert(s.substr(i - 2, 2));
	}
	fe(i, 8, n)
	{
		if(DP[1][i] == -1)
			dp(DP, s, n, i, 3);
		if(DP[1][i] == 1)
			a.insert(s.substr(i - 3, 3));
	}
	cout<<a.size()<<endl;
	for(auto i : a)
		cout<<i<<endl;
	
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
