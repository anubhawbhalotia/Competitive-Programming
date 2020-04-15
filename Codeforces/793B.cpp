#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<vector<vector<vector<bool>>>> vvvvb;
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
int dp(vvvvb &DP, vi &x, vi &y, int &n, int &m, vvc &a, 
	int r, int c, int d, int l)
{
	if(l == 3)
		return 0;
	if(a[r][c] == 'T')
		return 1;
	fe(i, 0, l)
	{
		if(DP[r][c][d][i] == 1)
			return 0;
	}
	f(i, l, 3)
		DP[r][c][d][i] = 1;
	f(i, 0, 4)
	{
		if(r + x[i] >= 0 && r + x[i] < n && c + y[i] >= 0 && c + y[i] < m
			&& a[r + x[i]][c + y[i]] != '*')
		{
			if(dp(DP, x, y, n, m, a, 
				r + x[i], c + y[i], i, l + (i != d)))
				return 1;
		}
	}
	return 0;
}
void solution(int tc)
{
	vi x = {0, -1, 0, 1}, y = {-1, 0, 1, 0};
	int n, m;
	cin>>n>>m;
	vvc a(n, vc(m));
	pt s;
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			cin>>a[i][j];
			if(a[i][j] == 'S')
			{
				s = mp(i, j);
			}
		}
	}
	vvvvb DP(n, vvvb(m, vvb(4, vb(3, 0))));
	int r = s.x, c = s.y;
	f(i, 0, 4)
	{
		DP[r][c][i][0] = 1;
		if(r + x[i] >= 0 && r + x[i] < n && c + y[i] >= 0 && c + y[i] < m
			&& a[r + x[i]][c + y[i]] != '*')
		{
			if(dp(DP, x, y, n, m, a, 
				s.x + x[i], s.y + y[i], i, 0))
			{
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
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
