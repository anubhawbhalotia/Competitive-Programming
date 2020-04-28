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
class Dsu
{
private:
	vi a; 
	int findRoot(int x)
	{
		vi temp;
		while(a[x] != x)
		{
			temp.pb(x);
			x = a[x];
		}
		for(auto i : temp)
		{
			a[i] = x;
		}
		return x;
	}
public:
	int build(int n)
	{
		a.resize(n);
		f(i, 0, n)
		{
			a[i] = i;
		}
		return 1;
	}
	int merge(int x, int y)
	{
		int temp = findRoot(y);
		a[findRoot(x)] = findRoot(y);
		return temp;
	}
	bool isSameSet(int x, int y)
	{
		return findRoot(x) == findRoot(y);
	}
};
class MstKruskal
{
private:
	vector<pair<int, pt>> mstEdges;	// {weight, {vertex 1, vertex 2}}
	int n;	// max number of nodes in the tree
	Dsu a;	// include a DSU class in the file
public:
	MstKruskal(int z)
	{
		n = z;
		a.build(n);
	}
	vector<pair<int, pt>> buildMst(vector<pair<int, pt>> &e)	
	{
		// returns edges included in mst along with their weights
		// {weight, {vertex 1, vertex 2}}
		sort(all(e));
		for(auto i : e)
		{
			if(a.isSameSet(i.Y.X, i.Y.Y) == false)
			{
				a.merge(i.Y.X, i.Y.Y);
				mstEdges.pb(i);
			}
		}
		return mstEdges;
	}
};
class LcaBinaryLifting
{
private:
	vvi up;
	vvi a;
	vi in, out;
	int n, root;
	int traverseDfs(vector <node> &tree, vi &in, vi &out, int root, int &c)
	{
		in[root] = c++;
		up[root][0] = tree[root].p.X;
		a[root][0] = tree[root].p.Y;
		int i = 0;
		while(up[root][i] != -1)
		{
			up[root][i + 1] = up[up[root][i]][i];
			if(up[root][i + 1] != -1)
				a[root][i + 1] = max(a[root][i], a[up[root][i]][i]);
			i++;
		}
		for(auto i : tree[root].c)
		{
			traverseDfs(tree, in, out, i.X, c);
		}
		out[root] = c++;
		return 1;
	}
	bool isAncestor(int x, int y)
	{
		if(x == -1 || y == -1)
			return 1;
		if(in[y] >= in[x] && out[y] <= out[x])
			return 1;
		return 0;
	}
public:
	int build(vector<node> &tree)
	{
		n = tree.size() - 1;
		root = tree[tree.size() - 1].a;
		up.resize(n, vi(32, -1));
		a.resize(n, vi(32, -1));
		in.resize(n);
		out.resize(n);
		int c = 0;
		traverseDfs(tree, in, out, root, c);
	}
	int lca(int x, int y, int &m)
	{
		if(isAncestor(x, y))
			return x;
		int l = 0, r = 31;
		while(l < r)
		{
			int mid = (l + r) / 2  + 1;
			if(isAncestor(up[x][mid], y))
			{
				r = mid - 1;
			}
			else
			{
				m = max(m, a[x][mid]);
				x = up[x][mid];
			}
		}
		if(isAncestor(up[x][l], y))
		{
			m = max(m, a[x][0]);
			return up[x][0];

		}
		else
		{
			m = max(m, a[x][l]);
			m = max(m, a[up[x][l]][0]);
			return up[up[x][l]][0];
		}
	}	
};
int solution(int tc)
{
	int n, m;
	cin>>n>>m;
	vector<pair<int, pt>> e;	// edge DS for kruskal's
	map <pt, int> b;	// mapping from edge to it's index in input
	vi x(m), y(m), z(m);
	f(i, 0, m)
	{
		cin>>x[i]>>y[i]>>z[i];
		b[{--x[i], --y[i]}] = i;
		b[{y[i], x[i]}] = i;
		e.pb({z[i], {x[i], y[i]}});
	}
	MstKruskal g(n);
	vector<pair<int, pt>> mst = g.buildMst(e);
	vector<vpt> adj(n);
	ll sum = 0;
	for(auto i : mst)
	{
		adj[i.Y.X].pb({i.Y.Y, i.X});
		adj[i.Y.Y].pb({i.Y.X, i.X});
		sum += (ll)i.X;
	}

	int root = 0;
	vector <node> tree(n + 1);
	tree[n].a = root;
	buildTreeFromAdj(tree, adj, root);

	set <pt> s;
	vl ans(m);
	for(auto i : mst)
	{
		s.insert(i.Y);
		ans[b[i.Y]] = sum;
	}
	LcaBinaryLifting h;
	h.build(tree);
	f(i, 0, m)
	{
		if(s.find({x[i], y[i]}) == s.end())
		{
			int maxWeight = INT_MIN;
			h.lca(x[i], y[i], maxWeight);
			h.lca(y[i], x[i], maxWeight);
			ans[i] = sum + (ll)z[i] - (ll)maxWeight;
		}
		cout<<ans[i]<<endl;
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
