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
vector<pii> v;
map <int, int> b;
int n;
class segTree
{
	vi t;
public:
	segTree()
	{
		t.resize(1000000);
	}
	void build(int node = 0, int st = 0, int en = n - 1)
	{
		if(st == en)
		{
			t[node] = v[st].fi;
			return ;
		}
		build(node*2+1, st, (st+en) / 2);
		build(node*2+2, (st+en) / 2 + 1, en);
		t[node] = t[node*2+1] + t[node*2+2];
	}
	int query(int l, int r, int node = 0, int st = 0, int en = n - 1)
	{
		if(st >= l && en <=r)
			return t[node];
		if(st > r || en < l)
			return 0;
		return query(l, r, node*2+1, st, (st+en) / 2) + 
			query(l, r, node*2+2, (st+en) / 2 + 1, en);
	}
	int update(int index, int node = 0, int st = 0, int en = n - 1)
	{
		if(index < st || index > en)
			return 0;
		if(st == en)
		{
			int temp = t[node];
			t[node] -= temp;
			return temp;
		}
		int temp = update(index, node*2+1, st, (st + en) / 2) + 
			update(index, node*2+2, (st + en) / 2 + 1, en);
		t[node] -= temp;
		return temp;
	}

};
void solution(int t)
{
	int m;
	cin>>n>>m;
	vi a(n);
	f(i, 0, n)
	{
		cin>>a[i];
		v.pb({a[i], i});
	}
	sort(all(v));
	f(i, 0, v.size())
		b[v[i].se] = i;
	segTree d;
	indexed_set <int> s;
	d.build();
	vi ans;
	fre(i, n - 1, 0)
	{
		d.update(b[i]);
		s.insert(b[i]);
		int st = 0, en = n - 1;
		while(st < en)
		{
			int mid = (st + en) / 2 + 1;
			if(d.query(0, mid) <= m - a[i])
				st = mid;
			else
				en = mid - 1;
		}
		if(d.query(0, st) <= m - a[i])
		{
			st -= s.order_of_key(st + 1);
			st++;
			ans.pb(i - st);
		}
		else
			ans.pb(i);
	}
	fre(i, n - 1, 0)
		cout<<ans[i]<<" ";
	cout<<endl;
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