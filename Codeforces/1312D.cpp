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
ll factorialNumInverse[1000001]; 
ll naturalNumInverse[1000001]; 
ll fact[1000001]; 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= 1000000; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
      for (int i = 2; i <= 1000000; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= 1000000; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
ll Binomial(ll N, ll R, ll p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 
  
ll p_mod(ll x, int y) 
{ 
    ll res = 1;   
    x = x % MOD;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % MOD; 
        y = y>>1; 
        x = (x*x) % MOD;
    } 
    return res; 
}  
int solution(int t)
{
	int n, m;
	cin>>n>>m;
	if(n == 2)
		return 0;
	int p = MOD;
	InverseofNumber(p);
	InverseofFactorial(p);
	factorial(p);
	ll a = p_mod(2, n-3);
	a = ((a*(n-2)) % MOD);
	a = (a *Binomial(m, n-1, p)) % MOD;
	return a;
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		cout<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   
