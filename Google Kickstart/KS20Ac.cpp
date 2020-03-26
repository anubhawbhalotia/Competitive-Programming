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
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
bool isCorr(int &x, vector<pt> &b, int k)
{
	int i = 0, z;
	while(i < (int)b.size())
	{
		if(b[i].fi > x)
			break;
		i++;
	}
	if(i == (int)b.size())
		return 1;
	while(i < (int)b.size())
	{
		z = ceil(b[i].fi / (double)x);
		// cout<<"z = "<<z<<endl;
		if(((z - 1) * b[i].se) <= k)
			k -= ((z - 1) * b[i].se);
		else
			return 0;
		i++;
	}
	return 1;
}
int solution(int t)
{
	int n, k, z;
	bool g;
	cin>>n>>k;
	vi a(n);
	vector<pt> b;
	cin>>a[0];
	map<int, int> m;
	f(i, 1, n)
	{
		cin>>a[i];
		z = a[i] - a[i - 1];
		// cout<<"z = "<<z<<endl;
		if(m.find(z) != m.end())
			m[z]++;
		else
			m[z] = 1;
	}
	// cout<<"b vector"<<endl;
	for(map<int,int> :: iterator it = m.begin(); it != m.end(); it++)
	{
		b.pb(mp(it->fi, it->se));
		// cout<<it->fi<<" "<<it->se<<endl;
	}
	// cout<<endl;

	int x = 1, y = 1000000000 - 1, mid;
	while(x < y)
	{
		mid = (x + y) / 2;
		g = isCorr(mid, b, k);
		// cout<<x<<" "<<mid<<" "<<y<<" "<<g<<" "<<k<<endl;
		if(g)
		{
			y = mid;
		}
		else
		{
			x = mid + 1;
		}
	}
	return x;
}
void testCase()
{
	int t = 1;
	cin>>t;
	f(i, 0, t)
	{
		cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   