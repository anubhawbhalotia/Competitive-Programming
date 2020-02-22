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
const int MOD = 400000000;
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
vi l, c, f, m;
vvi DP;
vi pFact(int a)
{
	vi ans;
	int temp = a;
	for(int i = 2; i*i <= a; i++)
	{
		if(temp % i == 0)
			ans.pb(i);
		while(temp % i == 0)
			temp /= i;
	}
	if(temp > 1)
		ans.pb(temp);
	return ans;
}
int dp(int x, int mask)
{
	if(x == n)
	{
		if(mask == (1<<((int)f.size())) - 1)
			return 0;
		return MOD;
	}
	if(DP[x][mask] != -1)
		return DP[x][mask];
	DP[x][mask] = min(MOD, min(dp(x+1, mask), dp(x+1, mask|m[x]) + c[x]));
	return DP[x][mask];
}
void solution(int t)
{
	int ans = MOD;
	cin>>n;
	l.resize(n);
	c.resize(n);
	m.resize(n);
	DP.resize(n, vi(1<<9));
	f(i, 0, n)
		cin>>l[i];
	f(i, 0, n)
		cin>>c[i];
	f(i, 0, n)
	{
		f = pFact(l[i]);
		f(j, 0, n)
		{
			m[j] = 0;
			f(k, 0, f.size())
			{
				if(l[j] % f[k] != 0)
					m[j] |= 1<<k;
			}
			f(e, 0, DP[0].size())
				DP[j][e] = -1;
		}
		ans = min(ans, dp(0, 0) + c[i]);
	}
	if(ans >= MOD)
		ans = -1;
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