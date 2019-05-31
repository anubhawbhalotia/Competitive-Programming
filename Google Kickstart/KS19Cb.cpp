#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
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
#define all(v) beg(v), en(v)
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
int r, c, k;
class segTree
{
	typedef struct treeArray{
		int mx, mn;
	}treeArray;
	treeArray *tree; 
public:
	segTree()
	{
		tree = new treeArray[8*300];
	}
	void build(vector <int> &a, int node = 0, int l = 0, int r = c - 1)
	{
		if(l == r)
		{
			tree[node].mx = a[l];
			tree[node].mn = a[l];
		}
		else
		{
			build(a, node * 2 + 1, l, (l + r) / 2);
			build(a, node * 2 + 2, (l + r) / 2 + 1, r);
			tree[node].mx = max(tree[node * 2 + 1].mx, tree[node * 2 + 2].mx);
			tree[node].mn = min(tree[node * 2 + 1].mn, tree[node* 2 + 2].mn);
		}
	}
	int query(int start, int end, int type, int node = 0, int l = 0, int r = c 
		- 1)
	{	
		if(l > end || r < start)
			return (type ? INT_MAX : INT_MIN);
		if(l >= start && r <= end)
			return (type ? tree[node].mn : tree[node].mx);
		int x = query(start, end, type, node * 2 + 1, l, (l + r) / 2);
		int y = query(start, end, type, node * 2 + 2, (l + r) / 2 + 1, r);
		return (type ? min(x, y) : max(x, y));
	}
};
vector < vector < int> > v, box, ps, ns;
void fillBox(segTree *tree[])
{
	f(i, 0, r)
	{
		segTree t = *tree[i];
		f(j, 0, c)
		{
			int start = j, end = c - 1;
			while(start < end)
			{
				int mid = (start + end) / 2 + 1;
				if(t.query(j, mid, 0) - t.query(j, mid, 1) <= k)
					start = mid;
				else
					end = mid - 1;
			}
			box[i][j] = start - j + 1;
		}
	}
}
void prevSmall()
{
	f(j, 0, c)
	{
		stack <int> s;
		fre(i, r - 1, 0)
		{
			while(s.empty() == false && box[s.top()][j] > box[i][j])
			{
				ps[s.top()][j] = i;
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty())
		{
			ps[s.top()][j] = -1;
			s.pop();
		}
	}
}
void nextSmall()
{
	f(j, 0, c)
	{
		stack <int> s;
		f(i, 0, r)
		{
			while(s.empty() == false && box[s.top()][j] > box[i][j])
			{
				ns[s.top()][j] = i;
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty())
		{
			ns[s.top()][j] = r;
			s.pop();
		}
	}
}
int findMaxHistogramAreaForEachCol()
{
	prevSmall();
	nextSmall();
	int ans = 0;
	f(i, 0, r)
		f(j, 0, c)
			ans = max(ans, (ns[i][j] -  ps[i][j] - 1 ) * box[i][j]);
	return ans;
}
void solution(int t)
{
	cin>>r>>c>>k;
	segTree *tree[r];
	v.resize(r, vector <int> (c));
	box.resize(r, vector <int> (c));
	ps.resize(r, vector <int> (c));
	ns.resize(r, vector <int> (c));
	f(i, 0, r)
		tree[i] = new segTree();
	int count = 0;
	for(auto &i : v)
	{
		for(auto &j : i)
			cin>>j;
		tree[count++]->build(i);
	}
	fillBox(tree);
	cout<<"Case #"<<t<<": "<<findMaxHistogramAreaForEachCol()<<endl;
	v.clear();
	box.clear();
	ps.clear();
	ns.clear();
}
void testCase()
{
	int t = 1;
	cin>>t;
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