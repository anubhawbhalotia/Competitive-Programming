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
void getAns(vvi &DP, vvi &s, vvi &ans, int l, int r, int x)
{
	if(l == r)
		return;
	getAns(DP, s, ans, l, DP[l][r] - 1 , x);
	getAns(DP, s, ans, DP[l][r], r, x + 1);
	if(s[l][DP[l][r] - 1] > s[DP[l][r]][r])
		ans.pb({0 + x, 1});
	else
		ans.pb({1 + x, -1});
}
vvi buildDP(vvi &DP, vi &a, int &n, vvi &s, int l, int r, int x)
{
	vvi ans;
	fe(i, 1, r - l)
	{
		fe(j, l, r - i)
		{
			fe(k, j + 1, j + i)
			{
				if(DP[j][k - 1] != -1 && DP[k][j + i] != -1)
				{
					if(s[j][k - 1] != s[k][j + i])
					{
						DP[j][j + i] = k;
						break;
					}
				}
			}
		}
	}
	if(DP[l][r] != -1)
		getAns(DP, s, ans, l, r, x);
	return ans;
}
int solution(vvi &ans)
{
	int n, k;
	cin>>n;
	vi a(n);
	f(i, 0, n)
		cin>>a[i];
	vvi s(n, vi(n, 0));
	f(i, 0, n)
	{
		int z = 0;
		f(j, i, n)
		{
			z += a[j];
			s[i][j] = z;
		}
	}
	cin>>k;
	vi b(k);
	f(i, 0, k)
		cin>>b[i];
	vvi DP(n, vi(n, -1));
	f(i, 0, n)
	{
		DP[i][i] = a[i];
	}
	int z = 0;
	int c = 0;
	int j = 0;
	f(i, 0, n)
	{
		if(j >= k)
			return -1;
		c++;
		z += a[i];
		if(z == b[j])
		{
			z = 0;
			if(c > 1)
			{
				// cout<<"calling buildDP "<<i - c + 1<<" "<<i<<" "<<c<<endl;
				vvi z_v = buildDP(DP, a, n, s, i - c + 1, i, j);
				if(z_v.empty())
					return -1;
				ans.insert(ans.end(), all(z_v));
			}
			c = 0;
			j++;
		}
		else if(z > b[j])
		{
			return -1;
		}
	}
	if(j < k)
		return -1;
	return 1;
}
void testCase()
{
	int t = 1;
	// cin>>t;
	unordered_map <int, char> m;
	m[1] = 'R';
	m[-1] = 'L';
	f(i, 0, t)
	{
		vvi ans;
		int z = solution(ans);
		if(z == -1)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			f(j, 0, ans.size())
			{
				cout<<ans[j][0] + 1<<" "<<m[ans[j][1]]<<endl;
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   