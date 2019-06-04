#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<long long> vl;
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
typedef struct node
{
	int parent;
	vi child;
}node;
vvi a;
vector <node> b;
void build()
{
	stack <int> s;
	s.push(1);
	while(!s.empty())
	{
		int temp = s.top();
		s.pop();
		f(i, 0, a[temp].size())
		{
			if(!b[a[temp][i]].child.size())
			{
				b[temp].child.pb(a[temp][i]);
				b[a[temp][i]].parent = temp;
				s.push(a[temp][i]);
			}
		}
	}
}
int q(char c, int u)
{
	int inp;
	cout<<c<<" "<<u<<endl;
	cin>>inp;
	return inp;
}
int getAllAtL(int r, int l)
{
	stack <pii> s;
	vi ans;
	s.push({r, 0});
	while(!s.empty())
	{
		pii temp = s.top();
		s.pop();
		if(temp.se == l)
		{
			ans.pb(temp.fi);
			continue;
		}
		f(i, 0, b[temp.fi].child.size())
			s.push({b[temp.fi].child[i], temp.se + 1});
	}
	return ans[ans.size() / 2];
}
int findLcs(int mid, int d)
{
	while(d--)
		mid = b[mid].parent;
	return mid;
}
int solve()
{
	int r = 1, l = q('d', 1); 
	while(l)
	{
		int mid = getAllAtL(r, l);
		l = q('d', mid) / 2;
		if(l == 0)
			return mid;
		int lcs = findLcs(mid, l);
		r = q('s', lcs);
		l--;
	}
	return r;
}
void solution(int t)
{
	int n, u, v;
	cin>>n;
	a.resize(n + 1);
	b.resize(n + 1);
	f(i, 0, n - 1)
	{
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	build();
	cout<<"! "<<solve()<<endl;
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