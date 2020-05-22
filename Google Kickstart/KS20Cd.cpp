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
class segTree
{
	// a generalised structure of segtree
private:
	int n;	//number of elements in original array
	vector<T> tree;	// array to store segment tree
	string type; // determines the segTree type
	T defVal;	// value to be returned when the range of current node lies completely outside the query range
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
			default:
				return (l + r);
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
		T l = buildTraverse(a, node*2+1, nodeLeft, (nodeLeft + nodeRight) / 2);
		T r = buildTraverse(a, node*2+2, (nodeLeft + nodeRight) / 2 + 1, nodeRight);
		tree[node] = operateLeftRight(l, r);
		return tree[node];
	}
	T queryTraverse(int node, int nodeLeft, int nodeRight, int st, int en)
	{
		// utility function for query()
		if(st <= nodeLeft && en >= nodeRight)
			return tree[node];
		if(st > nodeRight || en < nodeLeft)
			return defVal;
		T l = queryTraverse(node*2+1, nodeLeft, (nodeLeft + nodeRight) / 2, st, en);
		T r = queryTraverse(node*2+2, (nodeLeft + nodeRight) / 2 + 1, nodeRight, st, en);
		return operateLeftRight(l, r);
	}
	T updateTraverse(int node, int nodeLeft, int nodeRight, int index, T val)
	{
		// utility function for update
		if(index < nodeLeft || index > nodeRight)
			return tree[node];
		if(nodeLeft == nodeRight)
		{
			tree[node] = val;
			return tree[node];
		}
		T l = updateTraverse(node*2+1, nodeLeft, (nodeLeft + nodeRight) / 2, index, val);
		T r = updateTraverse(node*2+2, (nodeLeft + nodeRight) / 2 + 1, nodeRight, index, val);
		tree[node] = operateLeftRight(l, r);
		return tree[node];
	}
public:
	segTree(string s)
	{
		type = s;
		m["SUM"] = 0;
		m["MAX"] = 1;
		m["MIN"] = 2;
		switch(m[type])
		{
			case 0:
				defVal = 0;
				break;
			case 1:
				defVal = INT_MIN;
				break;
			case 2:
				defVal = INT_MAX;
				break;
		}
	}
	int build(vector<T> &a)
	{
		// builds a seg tree of type "type"
		n = a.size();
		tree.resize(5 * n);
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
};
ll solution(int tc)
{
	int n, q;
	cin>>n>>q;
	vi a(n), b(n);
	vl c(n);
	mi m;
	m[0] = 1;
	m[1] = -1;
	f(i, 0, n)
	{
		cin>>a[i];
		b[i] = m[i % 2] * a[i];	
		c[i] = m[i % 2] * (i + 1) * a[i];
	}
	segTree <int> x("SUM");
	x.build(b);
	segTree <ll> y("SUM");
	y.build(c);
	char t;
	int l, r;
	ll ans = 0;
	while(q--)
	{
		cin>>t>>l>>r;
		if(t == 'U')
		{
			x.update(l - 1, m[(l - 1) % 2] * r);
			y.update(l - 1, (m[(l - 1) % 2]) * (l * r));
		}
		else
		{
			r--;
			l--;
			ans += m[l % 2] * (y.query(l, r) - ((ll)l * (ll)x.query(l, r)));
		}
	}
	return ans;
}
void testCase()
{
	int tc = 1;
	cin>>tc;
	f(i, 0, tc)
	{
		// solution(i + 1);
		cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   