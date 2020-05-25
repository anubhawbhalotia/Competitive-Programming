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
#define watch1(x) cout <<(#x)<<" = "<<(x)<< endl
#define watch2(x, y) cout<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<endl
#define watch3(x, y, z) cout<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<" "<<\
	(#z)<<" = "<<z<<endl
#define log1(x) cout<<x<<endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MOD = 998244353;  
template <typename T>
class SegmentTree
{
	// a generalised structure of segtree
private:
	int n;	//number of elements in original array
	bool supportsLazy;
	vector<T> tree, lazy;	// array to store segment tree
	string type; // determines the segTree type
	T defVal, defValLazy;	// value to be returned when the range of current node lies completely outside the query range
	map <string, int> m; // mapping from segTree type to int number
	T operateLeftRight(T l, T r)	
	{
		// returns vaue after calcualtion of results from 2 nodes
		switch(m[type])
		{
			case 0:
				return (l + r);
			case 1:
				return max(l, r);
			case 2:
				return min(l, r);
			case 3:
				return l | r;
			default:
				return (l + r);
		}
	}
	T getAcuumulatedLazyReturnValue(int node ,int nodeLeft, 
		int nodeRight)
	{
		switch(m[type])
		{
			case 0: 
				return (nodeRight - nodeLeft + 1) * lazy[node];
			case 1:
				return lazy[node];
			case 2:
				return lazy[node];
			case 3:
				return lazy[node];
		}
	}
	T updateLazyNode(int node, int nodeLeft, int nodeRight)
	{
		if(lazy[node] != defValLazy)
		{
			tree[node] = getAcuumulatedLazyReturnValue(node, nodeLeft, 
				nodeRight);
			if(nodeLeft != nodeRight)
			{
				lazy[node*2+1] = lazy[node];
				lazy[node*2+2] = lazy[node];
			}
			lazy[node] = defValLazy;
		}
	}
	T buildTraverse(vector<T> &a, int node, int nodeLeft, int nodeRight)
	{
		// utility function for build() function
		if(nodeLeft == nodeRight)
		{
			tree[node] = a[nodeLeft];
			return tree[node];
		}
		T l = buildTraverse(a, node*2+1, nodeLeft, 
			(nodeLeft + nodeRight) / 2);
		T r = buildTraverse(a, node*2+2, (nodeLeft + nodeRight) / 2 + 1, 
			nodeRight);
		tree[node] = operateLeftRight(l, r);
		return tree[node];
	}
	T queryTraverse(int node, int nodeLeft, int nodeRight, int st, int en)
	{
		// utility function for query()
		if(supportsLazy)
		{
			updateLazyNode(node, nodeLeft, nodeRight);
		}
		if(st <= nodeLeft && en >= nodeRight)
		{
			return tree[node];
		}
		if(st > nodeRight || en < nodeLeft)
		{
			return defVal;
		}
		T l = queryTraverse(node*2+1, nodeLeft, (nodeLeft + nodeRight) / 2, 
			st, en);
		T r = queryTraverse(node*2+2, (nodeLeft + nodeRight) / 2 + 1, 
			nodeRight, st, en);
		return operateLeftRight(l, r);
	}
	T updateTraverse(int node, int nodeLeft, int nodeRight, int index, T val)
	{
		// utility function for update
		if(index < nodeLeft || index > nodeRight)
		{
			return tree[node];
		}
		if(nodeLeft == nodeRight)
		{
			tree[node] = val;
			return tree[node];
		}
		T l = updateTraverse(node*2+1, nodeLeft, (nodeLeft + nodeRight) / 2, 
			index, val);
		T r = updateTraverse(node*2+2, (nodeLeft + nodeRight) / 2 + 1, 
			nodeRight, index, val);
		tree[node] = operateLeftRight(l, r);
		return tree[node];
	}
	T updateTraverse(int node, int nodeLeft, int nodeRight, 
		int st, int en, T val)
	{
		// utility function for range update
		// supportsLazy must be true
		if(lazy[node] != defValLazy)
		{
			updateLazyNode(node, nodeLeft, nodeRight);
		}
		if(en < nodeLeft || st > nodeRight)
		{
			return tree[node];	
		}
		if(st <= nodeLeft && en >= nodeRight)
		{
			lazy[node] = val;
			tree[node] = getAcuumulatedLazyReturnValue(node, nodeLeft, 
				nodeRight);
			return tree[node];
		}
		T l = updateTraverse(node*2+1, nodeLeft, 
			(nodeLeft + nodeRight) / 2, st, en, val);
		T r = updateTraverse(node*2+2, (nodeLeft + nodeRight) / 2 + 1, 
			nodeRight, st, en, val);
		tree[node] = operateLeftRight(l, r);
		return tree[node];
	}
public:
	SegmentTree(string s, bool lazy)
	{
		type = s;
		supportsLazy = lazy;
		m["SUM"] = 0;
		m["MAX"] = 1;
		m["MIN"] = 2;
		m["OR"] = 3;
		switch(m[type])
		{
			case 0:
				defVal = 0;
				defValLazy = 0;
				break;
			case 1:
				defVal = INT_MIN;
				defValLazy = INT_MIN;
				break;
			case 2:
				defVal = INT_MAX;
				defValLazy = INT_MAX;
				break;
			case 3 : 
				defVal = (ll)0;
				defValLazy = (ll)0;
				break;
		}
	}
	int build(vector<T> &a)
	{
		// builds a seg tree of type "type"
		n = a.size();
		tree.resize(5 * n);
		if(supportsLazy)
		{
			lazy.resize(5 * n, defValLazy);
		}
		buildTraverse(a, 0, 0, n - 1);
		return 1;
	}
	T query(int st, int en)
	{
		// query  range => [st, en] (inclusive)
		if(st > en)
			return defVal;
		return queryTraverse(0, 0, n - 1, st, en);
	}
	int update(int index, T val)
	{
		// update a particular index with a val
		// not for range update
		updateTraverse(0, 0, n - 1, index, val);
		return 1;
	}
	int update(int st, int en, T val)
	{
		// update index [st, en] to val
		// range update
		// supportsLazy must be true
		updateTraverse(0, 0, n - 1, st, en, val);
		return 1;
	}
};
int dfs(vector<vpt> &adj, vi &in, vi &ot, int &c, int curr, int p, vl &a)
{
	a.pb(curr);
	in[curr] = ++c;
	for(auto i : adj[curr])
	{
		if(i.X != p)
		{
			dfs(adj, in, ot, c, i.X, curr, a);
		}
	}
	ot[curr] = c;
	return 1;
}
template <typename T>
int bitwiseGetCountSetBit(T a)
{
	int c = 0;
	while(a)
	{
		if(a % 2 == 1)
			c++;
		a /= 2;
	}
	return c;
}
int solution(int tc)
{
	int n, m, x, y;
	cin>>n>>m;
	vi c(n);
	f(i, 0, n)
	{
		cin>>c[i];
	}
	vector<vpt> adj(n);
	f(i, 0, n - 1)
	{
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb({y, 0});
		adj[y].pb({x, 0});
	}
	int cnt = -1, root = 0;
	vi in(n), ot(n);
	vl a;
	dfs(adj, in, ot, cnt, root, -1, a);
	f(i, 0, a.size())
	{
		a[i] = (ll)1<<(c[a[i]] - 1);
	}
	SegmentTree <ll> s("OR", 1);
	s.build(a);
	int t;
	ll col;
	while(m--)
	{
		cin>>t>>x;
		x--;
		if(t == 1)
		{
			cin>>col;
			s.update(in[x], ot[x], (ll)1<<(col - 1));
		}
		else
		{
			ll ans = s.query(in[x], ot[x]);
			log1(bitwiseGetCountSetBit(ans));
		}
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
