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
vvi t;
typedef struct node
{
	vi c;
	int p;
	vi c_d;
	int m1, m2, p_d;
}node;
vector <node> s;
vector <bool> f;
unordered_set <int> p;
int d, ans;
void buildTree(int root)
{
	s[root].m1 = s[root].m2 = s[root].p_d = -1;
	f(i, 0, t[root].size())
	{
		if(!f[t[root][i]])
		{
			f[t[root][i]] = 1;
			s[t[root][i]].p = root;
			s[root].c.pb(t[root][i]);
			s[root].c_d.pb(-1);
			buildTree(t[root][i]);
		}
	}
}
int dfsDown(int root)
{
	f(i, 0, s[root].c.size())
	{
		int val = dfsDown(s[root].c[i]);
		if(val != -1)
		{
			s[root].c_d[i] = ++val;
			if(val > s[root].m1)
			{
				s[root].m2 = s[root].m1;
				s[root].m1 = val;
			}
			else if(val > s[root].m2)
				s[root].m2 = val;
		}
	}
	if(p.find(root) != p.end())
	{
		if(s[root].m1 == -1)
			s[root].m1 = 0;
		else if(s[root].m2 == -1)
			s[root].m2 = 0;
	}
	return s[root].m1;
}
int dfsUp(int root)
{
	queue <int> q, x;
	if(p.find(root) != p.end())
		s[root].p_d = 0;
	if(max(s[root].m1, s[root].p_d) <= d)
		ans++;
	f(i, 0, s[root].c.size())
	{
		q.push(s[root].c[i]);
		x.push(i);
	}
	while(!q.empty())
	{
		int sz = q.size();
		while(sz--)
		{
			int temp = q.front(), M, y = x.front();
			x.pop();
			q.pop();
			if(s[s[temp].p].c_d[y] == s[s[temp].p].m1)
				M = max(s[s[temp].p].m2, s[s[temp].p].p_d);
			else
				M = max(s[s[temp].p].m1, s[s[temp].p].p_d);
			if(M != -1)
				s[temp].p_d = ++M;
			else if(p.find(temp) != p.end())
				s[temp].p_d = 0;
			if(max(s[temp].m1, s[temp].p_d) <= d)
				ans++;
			f(i, 0, s[temp].c.size())
			{
				q.push(s[temp].c[i]);
				x.push(i);
			}
		}
	}
}
void solution()
{
	int n, m;
	ans = 0;
	cin>>n>>m>>d;
	int x, y;
	f(i, 0, m)
	{
		cin>>x;
		p.insert(--x);
	}
	t.resize(100000);
	f(i, 0, n-1)
	{
		cin>>x>>y;
		t[--x].pb(--y);
		t[y].pb(x);
	}
	s.resize(100000);
	f.resize(100000, 0);
	f[0] = 1;
	buildTree(0);
	dfsDown(0);
	dfsUp(0);
	cout<<ans<<endl;
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