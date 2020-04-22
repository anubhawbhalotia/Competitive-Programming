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
int bsl(vi &a, int l, int r, int val)
{
	int m;
	while(l < r)
	{
		m = (l + r) / 2;
		if(a[m] >= val)
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}
	return l;
}
int bsr(vi &a, int l, int r, int val)
{
	int m;
	while(l < r)
	{
		m = (l + r) / 2 + 1;
		if(a[m] <= val)
		{
			l = m;
		}
		else
		{
			r = m - 1;
		}
	}
	if(a[l] <= val)
		return l;
	return a.size();
}
void solution(int t)
{
	int n, k, z, x = 0, y, s = INT_MAX;
	cin>>n>>k;
	vi a(n), b, ans;
	f(i, 0, n)
	{
		cin>>a[i];
	}
	map <int, int> m;
	f(i, 0, n/2)
	{
		z = a[i] + a[n - i - 1];
		if(m.find(z) == m.end())
		{
			m[z] = 0;
		}
		m[z]++;
	}
	for(auto i : m)
	{
		b.pb(i.x);
		ans.pb(-i.y);
	}
	int d = b.size();
	//cout<<"d  = "<<d<<endl;
	vi c(d, 0);
	int g = INT_MAX;
	int h = INT_MIN;
	f(i, 0, n / 2)
	{
		y = bsl(b, 0, d - 1, min(a[i], a[n - i - 1]) + 1); //will always find
		g = min(g, min(a[i], a[n - i - 1]) + 1);
		h = max(h, max(a[i], a[n - i - 1]) + k);
		z = bsr(b, 0, d - 1, max(a[i], a[n - i - 1]) + k); //return b if not found
		//cout<<"y = "<<y<<" z = "<<z<<endl;
		c[0] += 2;
		c[y] -= 2;
		c[y] += 1;
		if(z < d - 1)
		{
			//cout<<"yes"<<endl;
			c[z + 1] -= 1;
			c[z + 1] += 2;
		}
	}
	z = 0;
	f(i, 0, d)
	{
		z += c[i];
		//cout<<"z = "<<z<<endl;
		ans[i] += z;
		s = min(s, ans[i]);
		//cout<<"s = "<<s<<endl;
	}
	if(g < h)
		s = min(s, n / 2);
	cout<<s<<endl;
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
