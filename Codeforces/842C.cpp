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
template <typename T> T gcd(T a, T b) 
{
	return b == 0 ? a : gcd(b, a % b);
}
vi getDivisors(int n)
{
	vi ans;
	fe(i, 1, (int)sqrt(n))
	{
		if(n % i == 0)
		{
			ans.pb(i);
			if(i * i != n)
				ans.pb(n / i);
		}
	}
	sort(all(ans));
	return ans;
}
int traverse(vector<vpt> &adj, vi &a, vi &t, vi &ans,
	map <int, int> &b, int x, int l, int p)
{
	int z = INT_MIN;
	for(auto &i : b)
	{
		i.Y += (int)(a[x] % i.X == 0);
		if(i.Y >= l)
		{
			z = i.X;
		}
	}
	if(l)
	{
		t[x] = gcd(t[p], a[x]);
	}
	ans[x] = max(t[x], z);
	for(auto i : adj[x])
	{
		if(i.X != p)
		{
			traverse(adj, a, t, ans, b, i.X, l + 1, x);
		}
	}
	for(auto &i : b)
	{
		i.Y -= (int)(a[x] % i.X == 0);
		if(i.X > a[x])
		{
			break;
		}
	}
	return 1;
}
int solution(int tc)
{
	int n;
	cin>>n;
	vi a(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	vector<vpt> adj(n);
	int x, y;
	f(i, 0, n - 1)
	{
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb({y, 1});
		adj[y].pb({x, 1});
	}
	vi d = getDivisors(a[0]);
	map <int, int> b;
	int root = 0;
	vi t(n, 0), ans(n);
	for(auto i : d)
	{
		b[i] = 0;
	}
	traverse(adj, a, t, ans, b, root, 0, 0);
	f(i, 0, n)
	{
		// cout<<max(ans[i], t[i])<<" ";
		cout<<ans[i]<<" ";

	}
	cout<<endl;
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

