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
ll DP[5001][5001];
ll F[5001];
ll dp(int a, int b)
{
	if(DP[a][b])
		return DP[a][b];
	if(a == b || b == 0)
	{
		DP[a][b] = 1;
		return DP[a][b];
	}
	DP[a][b] = DP[a][a-b] = (dp(a-1, b) + dp(a-1, b-1)) % MOD;
	return DP[a][b]; 
}
ll fact(int a)
{
	if(F[a])
		return F[a];
	if(a == 0)
	{
		F[a] = 1;
		return F[a];
	}
	F[a] = (fact(a - 1) * a) % MOD;
	return F[a];
}
void solution(int t)
{
	int a, b, c;
	cin>>a>>b>>c;
	memset(DP, 0, sizeof(DP));
	memset(F, 0, sizeof(F));
	ll x = 1, y = 1, z = 1;
	fe(i, 1, min(a, b))
		x = (x + ((((dp(a, i) * dp(b, i)) % MOD) * fact(i)) % MOD)) % MOD;
	fe(i, 1, min(b, c))
		y = (y + ((((dp(b, i) * dp(c, i)) % MOD) * fact(i)) % MOD)) % MOD;
	fe(i, 1, min(a, c))
		z = (z + ((((dp(a, i) * dp(c, i)) % MOD) * fact(i)) % MOD)) % MOD;
	cout<<(((x*y) % MOD) * z) % MOD<<endl;
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