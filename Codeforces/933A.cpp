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
int n;
vi a;
vvi e_in, s_in;
int solve()
{
	int f = 0;
	f(i, 0, n)
	{
		int a_m = 0, b_m = 0, b = 0;
		fre(j, i, 0)
		{
			int ans = 0, ans2 = 0;
			if(a[j] == 2)
			{
				b++;
				if(a_m)
					b_m = max(a_m, b_m) + 1;
			}
			else
				a_m++;
			ans2 = b;
			if(j > 0)
			{
				ans += e_in[0][j-1];
				ans2 += max(e_in[0][j-1], e_in[1][j-1]);
			}
			int temp_1 = a_m;
			int temp_2 = b_m;
			if(i < n - 1)
			{
				temp_1 += max(s_in[0][i+1], s_in[1][i+1]);
				temp_2 += s_in[1][i+1];
				ans2 += s_in[1][i+1];
			}
			ans += max(temp_1, temp_2);
			f = max(f, max(ans, ans2));
		}
	}
	cout<<f<<endl;
}
void solution(int t)
{
	cin>>n;
	a.resize(n);
	f(i, 0, n)
		cin>>a[i];
	e_in.resize(2, vi(n, 0)), s_in.resize(2, vi(n, 0));
	int a_m = 0, b_m = 0, x_m = 0, y_m = 0;
	f(i, 0, n)
	{
		if(a[i] == 2)
		{
			e_in[1][i] = max(a_m, b_m) + 1;
			b_m = e_in[1][i];
			if(i)
				e_in[0][i] = e_in[0][i-1];
		}
		else
		{
			e_in[0][i] = ++a_m;
			if(i)
				e_in[1][i] = e_in[1][i-1];
		}
		if(a[n-i-1] == 1)
		{
			s_in[0][n-i-1] = max(x_m, y_m) + 1;
			x_m = s_in[0][n-i-1];
			if(i)
				s_in[1][n-i-1] = s_in[0][n-i];
		}
		else
		{
			s_in[1][n-i-1] = ++y_m;
			if(i)
				s_in[0][n-i-1] = s_in[0][n-i];
		}
	}
	solve();
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