#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
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
void solution(int t)
{
	int n;
	cin>>n;
	vi x(n), h(n);
	f(i, 0, n)
		cin>>x[i]>>h[i];
	vector <vector <int> > dp;
	dp.resize(3, vector <int>(n, 0));
	dp[1][n - 1] = 1;
	if(n == 1 || x[n - 1] - h[n - 1] > x[n - 2])
		dp[2][n - 1] = 1;
	fre(i, n - 2, 0)	
	{
		//no cut
		dp[0][i] = max(dp[0][i + 1], max(dp[1][i + 1], dp[2][i + 1]));
		//right cut
		if(x[i] + h[i] < x[i + 1])
			dp[1][i] = 1 + max(dp[0][i + 1], dp[1][i + 1]);
		if(x[i] + h[i] < x[i + 1] - h[i + 1])
			dp[1][i] = max(dp[1][i], 1 + dp[2][i + 1]);
		//left cut
		if((i > 0 && x[i] - h[i] > x[i - 1]) || i == 0)
			dp[2][i] = 1 + max(dp[0][i + 1], max(dp[1][i + 1], dp[2][i + 1]));
	}
	cout<<max(dp[0][0], max(dp[1][0], dp[2][0]))<<endl;
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