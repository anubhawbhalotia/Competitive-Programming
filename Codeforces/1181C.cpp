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
vvi h, v; 
int n, m;
vector <string> s;
void buildHorizontal()
{
	f(i, 0, n)
	{
		stack <int> t;
		t.push(0);
		f(j, 1, m)
		{
			while(!t.empty() && s[i][t.top()] != s[i][j])
			{
				h[i][t.top()] = j - t.top();
				t.pop();
			}
			t.push(j);
		}
		while(!t.empty())
		{
			h[i][t.top()] = m - t.top();
			t.pop();
		}
	}
}
void buildVertical()
{
	f(j, 0, m)
	{
		stack <int> t;
		t.push(0);
		f(i, 1, n)
		{
			while(!t.empty() && s[t.top()][j] != s[i][j])
			{
				v[t.top()][j] = i - t.top();
				t.pop();
			}
			t.push(i);
		}
		while(!t.empty())
		{
			v[t.top()][j] = n - t.top();
			t.pop();
		}
	}
}
class segTree
{
	vi t;
public:
	segTree()
	{
		t.resize(5000);
	}
	void build(int col, int node = 0, int st = 0, int en = n - 1)
	{
		if(st == en)
		{
			t[node] = h[st][col];
			return ;
		}
		build(col, node*2+1, st, (st + en) / 2);
		build(col, node*2+2, (st + en) / 2 + 1, en);
		t[node] = min(t[node*2+1], t[node*2+2]);
	}
	int query(int l, int r, int node = 0, int st = 0, int en = n - 1)
	{
		if(st >= l && en <= r)
			return t[node];
		if(l > en || r < st)
			return INT_MAX;
		return min(query(l, r, node*2+1, st, (st + en) / 2),
			query(l, r, node*2+2, (st + en) / 2 + 1, en));
	}
};
int ex(int r, int c)
{
	int sa = v[r][c];
	r += sa;
	if(r >= n)
		return -1;
	int sb = v[r][c];
	r += sb;
	if(r >= n || sb != sa)
		return -1;
	int sc = v[r][c];
	if(sc < sb)
		return -1;
	return r + sb - 1;
}
void solution(int t)
{
	cin>>n>>m;
	s.resize(n);
	h.resize(n, vi(m));
	v.resize(n, vi(m));
	f(i, 0, n)
		cin>>s[i];
	buildHorizontal();
	buildVertical();
	vector <segTree> r(m + 1);
	f(i, 0, m)
		r[i].build(i);
	ll ans = 0;
	f(j, 0, m)
	{
		f(i, 0, n)
		{
			int end = ex(i, j);
			if(end != -1)
				ans += (ll)(r[j].query(i, end));
		}
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