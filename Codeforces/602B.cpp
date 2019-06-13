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
int n;
vi a;
class segTree
{
	vi M, m;
public:
	segTree()
	{
		M.resize(600000);
		m.resize(600000);
	}
	void build(int node = 0, int st = 0, int en = n - 1)
	{
		if(st == en)
		{
			M[node] = a[st];
			m[node] = a[st];
			return ;
		}
		build(node*2+1, st, (st + en) / 2);
		build(node*2+2, (st + en) / 2 + 1, en);
		M[node] = max(M[node*2+1], M[node*2+2]);
		m[node] = min(m[node*2+1], m[node*2+2]);
	}
	int query(int q, int l, int r, int node = 0, int st = 0, int en = n - 1)
	{
		if(st >= l && en <= r)
			return ((q)?m[node]:M[node]);
		if(l > en || r < st)
			return (q)?INT_MAX:INT_MIN;
		int a = query(q, l, r, node*2+1, st, (st+en)/2);
		int b = query(q, l, r, node*2+2, (st+en)/2+1, en);
		return (q)?min(a, b):max(a, b);
	}
};
void solution(int t)
{
	cin>>n;
	a.resize(n);
	f(i, 0, n)
		cin>>a[i];	
	segTree b;
	b.build();
	int ans = INT_MIN;
	f(i, 0, n)
	{
		int start = i, end = n - 1;
		while(start < end)
		{
			int mid = (start + end) / 2 + 1;
			if(b.query(0, i, mid) - b.query(1, i, mid) <= 1)
				start = mid;
			else
				end = mid - 1;
		}
		ans = max(ans, start - i + 1);
	}
	cout<<ans<<endl;
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