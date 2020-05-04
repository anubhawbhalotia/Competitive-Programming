#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<vector<long long>>> vvvl;
typedef vector<pair<int, int>> vpt;
typedef vector<pair<long long, long long>> vptl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
typedef map<int, int> mi;
typedef map<long long, long long> ml;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define X first
#define Y second
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
typedef struct node
{
	int a;	// value at vertex
	pt p;	// {index of parent, weight between this and parent}
	vpt c;	// {index of child, weight between this and child}
	int temp;
	node()
	{
		a = 0;
		p = {-1, 0};
	}
}node;
int buildTreeFromAdj(vector<node> &tree, vector<vpt> &adj, int root)
{
	for(auto i : adj[root])
	{
		if(i.X != tree[root].p.X)
		{
			tree[i.X].p = {root, i.Y};
			tree[root].c.pb(i);
			buildTreeFromAdj(tree, adj, i.X);
		}
	}
	return 1;
}
int traverse(vector<node> &tree, int &s, vi &ans, vi &t, int x)
{
	tree[x].temp = t[x];
	for(auto i : tree[x].c)
	{
		int r = traverse(tree, s, ans, t, i.X);
		if(r == 1e9)
			return r;
		if(r == s / 3)
		{
			ans.pb(i.X);
			if(ans.size() == 2)
			{
				return 1e9;
			}
		}
		else
		{
			tree[x].temp += r;
		}
	}
	return tree[x].temp;
}
int solution(int tc)
{
	int n;
	cin>>n;
	int p, root, s = 0;
	vector <vpt> adj(n);
	vi t(n);
	f(i, 0, n)
	{
		cin>>p>>t[i];
		p--;
		adj[i].pb({p, 1});
		if(p == -1)
			root = i;
		else
			adj[p].pb({i, 1});	
		s += t[i];
		
	}
	if(s % 3 != 0)
	{
		cout<<"-1"<<endl;
		return 1;
	}
	vector <node> tree(n + 1);
	tree[n].a = root;
	buildTreeFromAdj(tree, adj, root);
	vi ans;
	traverse(tree, s, ans, t, root);
	if(ans.size() == 2)
	{
		f(i, 0, 2)
		{
			cout<<ans[i] + 1<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
	return 1;
}
void testCase()
{
	int tc = 1;
	// cin>>tc;
	f(i, 0, tc)
	{
		solution(i + 1);
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

