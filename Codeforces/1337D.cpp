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
int bsl(vi &a, int st, int en, int val)
{
	int m;
	while(st < en)
	{
		m = ((st + en) / 2) + 1;
		if(a[m] <= val)
		{
			st = m;
		}
		else
		{
			en = m - 1;
		}
	}
	return a[en];
}
int bsg(vi &a, int st, int en, int val)
{
	int m;
	while(st < en)
	{
		m = ((st + en) / 2);
		if(a[m] < val)
		{
			st = m + 1;
		}
		else
		{
			en = m;
		}
	}
	return a[en];
}
void solution(int t)
{
	int r, g, b;
	cin>>r>>g>>b;
	vi x(r), y(g), z(b);
	f(i, 0, r)
	{
		cin>>x[i];
	}
	f(i, 0, g)
	{
		cin>>y[i];
	}
	f(i, 0, b)
	{
		cin>>z[i];
	}
	sort(x.begin(), x.begin() + r);
	sort(y.begin(), y.begin() + g);
	sort(z.begin(), z.begin() + b);
	ll ans = 4000000000000000000 , c, d, e, k;
	f(i, 0, r)
	{
		c = x[i];
		d = bsl(y, 0, g - 1, x[i]);
		e = bsg(z, 0, b - 1, x[i]);
		k = (abs(c - d) * abs(c - d));
		k += (abs(d - e) * abs(d - e)); 
		k += (abs(e - c) * abs(e - c));
		if(ans > k)
			ans = k;

		d = bsg(y, 0, g - 1, x[i]);
		e = bsl(z, 0, b - 1, x[i]);
		k = (abs(c - d) * abs(c - d));
		k += (abs(d - e) * abs(d - e)); 
		k += (abs(e - c) * abs(e - c));
		if(ans > k)
			ans = k;

	}
	f(i, 0, g)
	{
		d = y[i];
		c = bsl(x, 0, r - 1, y[i]);		
		e = bsg(z, 0, b - 1, y[i]);
		k = (abs(c - d) * abs(c - d));
		k += (abs(d - e) * abs(d - e)); 
		k += (abs(e - c) * abs(e - c));
		if(ans > k)
			ans = k;

		c = bsg(x, 0, r - 1, y[i]);		
		e = bsl(z, 0, b - 1, y[i]);
		k = (abs(c - d) * abs(c - d));
		k += (abs(d - e) * abs(d - e)); 
		k += (abs(e - c) * abs(e - c));
		if(ans > k)
			ans = k;
	}
	f(i, 0, b)
	{
		e = z[i];
		c = bsl(x, 0, r - 1, z[i]);
		d = bsg(y, 0, g - 1, z[i]);
		k = (abs(c - d) * abs(c - d));
		k += (abs(d - e) * abs(d - e)); 
		k += (abs(e - c) * abs(e - c));
		if(ans > k)
			ans = k;

		c = bsg(x, 0, r - 1, z[i]);
		d = bsl(y, 0, g - 1, z[i]);
		k = (abs(c - d) * abs(c - d));
		k += (abs(d - e) * abs(d - e)); 
		k += (abs(e - c) * abs(e - c));
		if(ans > k)
			ans = k;
	}
	cout<<ans<<endl;
}
void testCase()
{
	int t = 1;
	cin>>t;
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
