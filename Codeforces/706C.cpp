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
const ll MAX_VAL = 1e15;
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
	ll n;
	cin>>n;
	vl c(n);
	string s[n], r[n];
	f(i, 0, n)
		cin>>c[i];
	f(i, 0, n)
	{
		cin>>s[i];
		r[i] = s[i];
		reverse(all(r[i]));
	}
	vvl d(2, vl(n, MAX_VAL));
	d[0][n - 1] = 0;
	d[1][n - 1] = c[n - 1];
	fre(i, n - 2, 0)
	{
		//do not reverse
		if(s[i] <= s[i + 1])
			d[0][i] = min(d[0][i], d[0][i + 1]);
		if(s[i] <= r[i + 1])
			d[0][i] = min(d[0][i], d[1][i + 1]);
		//reverse string
		if(r[i] <= s[i + 1])
			d[1][i] = min(d[1][i], c[i] + d[0][i + 1]);
		if(r[i] <= r[i + 1])
			d[1][i] = min(d[1][i], c[i] + d[1][i + 1]);
	}
	ll ans = min(d[0][0], d[1][0]);
	if(ans >= MAX_VAL)
		cout<<"-1"<<endl;
	else
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