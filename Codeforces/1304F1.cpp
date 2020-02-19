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
vi dp_1, dp_2;
class segTree
{
	vi g;
public:
	segTree()
	{
		g.resize(1000000, 0);
	}
	int build(vi &a, int node = 0, int l = 0, int r = dp_1.size() - 1)
	{
		if(l == r)
		{
			g[node] = a[l];
			return g[node];
		}
		g[node] = max(build(a, node*2+1, l, (l+r)/2),build(a, node*2+2, (l+r)/2+1, r));
		return g[node];
	}
	int query(int lo, int hi, int node = 0, int l = 0, int r = dp_1.size() - 1)
	{
		if(lo > r || hi < l || lo > hi)
			return 0;
		if(lo <= l && hi >= r)
			return g[node];
		return max(query(lo, hi, node*2+1, l, (l+r)/2), query(lo, hi, node*2+2, (l+r)/2+1, r));
	}
};
void solution()
{
	int n, m, k;
	cin>>n>>m>>k;
	int b = m-k+1, temp = 0;
	vvi a(n, vi(m)), s(n, vi(b, 0));
	f(i, 0, n)
		f(j, 0, m)
			cin>>a[i][j];
	f(i, 0, n)
	{
		temp = 0;
		f(j, 0, k)
			temp += a[i][j];
		s[i][0] = temp;
		s[max(0, i-1)][0] += (i>0) ? s[i][0] : 0;
		f(j, k, m)
		{
			temp = temp - a[i][j - k] + a[i][j];
			s[i][j-k+1] = temp;
			s[max(0, i-1)][j-k+1] += (i>0) ? s[i][j-k+1] : 0;;
		}
	}	
	dp_1 = s[n-1];
	segTree t;
	fre(i, n-2, 0)
	{
		dp_2 = dp_1;
		t.build(dp_2);
		f(j, 0, b)
		{
			dp_1[j] = max(t.query(j + k, b - 1), t.query(0, j - k)) + s[i][j];
			temp = 0;
			f(p, j, j+k)
			{
				temp += a[i+1][p];
				if(p-k+1 >= 0)
					dp_1[j] = max(dp_1[j], dp_2[p-k+1] + s[i][j] - temp);
			}
			f(p,j,j+k-1)
			{
				temp -= a[i+1][p];
				if(p+k < m)
					dp_1[j] = max(dp_1[j], dp_2[p+1] + s[i][j] - temp);
			}
		}
	}
	cout<<*(max_element(all(dp_1)))<<endl;
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		solution();
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   