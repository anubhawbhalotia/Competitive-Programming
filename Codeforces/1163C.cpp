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
vi x, y, n;
set <pair < pii, int > > s;
map <pii, int> m;
void solution(int t)
{
	int n, a, b, c, g;
	ll ans = 0;
	cin>>n;
	x.resize(n);
	y.resize(n);
	f(i, 0, n)
	{
		cin>>x[i]>>y[i];
		x[i] += 10000;
		y[i] += 10000;
	}
	f(i, 0, n)
	{
		f(j, i + 1, n)
		{
			a = y[j] - y[i];
			b = x[j] - x[i];
			c = (y[i]*x[j]) - (y[j]*x[i]);
			g = gcd(gcd(a, b), c);
			a /= g;
			b /= g;
			c /= g;
			s.insert({{a, b}, c});
		}	
	}
	for(auto it = s.begin(); it != s.end(); it++)
	{
		g = gcd(it->fi.fi, it->fi.se);
		m[{it->fi.fi / g, it->fi.se / g}]++;
	}
	for(auto it = s.begin(); it != s.end(); it++)
	{
		g = gcd(it->fi.fi, it->fi.se);
		ans += (ll)s.size() - (ll)m[{it->fi.fi / g, it->fi.se / g}];
	}
	cout<<ans/2<<endl;

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