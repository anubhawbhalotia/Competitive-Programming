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
int solution(int t)
{
	int n;
	cin>>n;
	vi a(n), d;
	f(i, 0, n)
		cin>>a[i];
	fe(i, 1, (int)sqrt(n))
	{
		if(n % i == 0)
		{
			if(n / i > 2)
				d.pb(i);
			if(i > 2 && i != (n/i))
				d.pb(n / i);
		}
	}
	if((int)sqrt(n)*(int)sqrt(n) == n && n / (int)sqrt(n) > 2)
		d.pb((int)sqrt(n));
	vvi dp(n, vi(d.size(), -1));
	int flag = 0;
	f(i, 0, n)
	{
		f(j, 0, d.size())
		{
			int f = (i-d[j] < 0) ? n - abs(i-d[j]) : (i-d[j])%n;
			dp[i][j] = abs(dp[f][j]) * a[i];
			if(dp[i][j]*flag)
				return 1;
		}
		if(flag == 0 && i == n-1)
		{
			flag = 1;
			i = -1;
		}
	}
	return 0;
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		if(solution(i + 1))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   