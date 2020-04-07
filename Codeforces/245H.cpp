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
// vvl DP(5001, vi(5001)), a(5001, vi(5001));
// vvi DP(5001, vi(5001)), a(5001, vi(5001));
// vvi a;
// vector<vector<bool>> DP;
bool DP[5001][5001];
int a[5001][5001];
void solution(int t)
{
	string s;
	cin>>s;
	int n = s.length(), q;
	// DP.resize(n + 1, vector<bool>(n));
	// a.resize(n, vi(n));
	f(i, 0, n)
	{
		DP[i][i] = 1;
		a[i][i] = 1;
		DP[i + 1][i] = 1;
	}
	fe(i, 2, n)
	{
		fe(j, 0, n - i)
		{
			if(s[j] == s[j + i - 1] && DP[j + 1][j + i - 2] == 1)
			{
				DP[j][j + i - 1] = 1; 
			}
			a[j][j + i - 1] = a[j][j + i - 2] + a[j + 1][j + i - 1] - 
				a[j + 1][j + i - 2] + DP[j][j + i - 1];
		}
	}
	cin>>q;
	int l, r;
	f(i, 0, q)
	{
		// scanf("%d %d", &l, &r);
		cin>>l>>r;
		l--;
		r--;
		cout<<a[l][r]<<endl;
	}

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