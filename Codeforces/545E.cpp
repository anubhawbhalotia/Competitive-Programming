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
class Dijkstra
{
private:
	vl shortestDis;
	int n;	//n => number of nodes in the graph
	vi p;
public:
	Dijkstra(int z)
	{
		n = z;
		shortestDis.resize(n, 1e15);
		p.resize(n, -1);
	}
	vi calculateShortestDis(vector<vpt> &adj, int source, map<pt, int>  &b, vi w)
	{
		// input adjacency list
		// return shortest distance between source and every vertex in the graph
		vi vis(n, 0);
		set <pair<ll, int>> notIncl;
		shortestDis[source] = 0;
		ll weight;
		f(i, 0, n)
		{
			notIncl.insert({shortestDis[i], i});
		}
		pair<ll, int>  first;
		while(!notIncl.empty())
		{
			first = *(notIncl.begin());
			vis[first.Y] = 1;
			notIncl.erase(notIncl.begin());
			for(auto i : adj[first.Y])
			{
				if(vis[i.X] == 0)
				{
					weight = (ll)i.Y + shortestDis[first.Y];
					if(weight < shortestDis[i.X])
					{
						notIncl.erase({shortestDis[i.X], i.X});
						shortestDis[i.X] = weight;
						notIncl.insert({weight, i.X});
						p[i.X] = first.Y;
					}
					else if(weight == shortestDis[i.X])
					{
						if(w[b[{i.X, first.Y}]] < w[b[{i.X, p[i.X]}]])
						{
							p[i.X] = first.Y;
						}
					}
				}
			}
		}
		return p;
	}
};     
int solution(int tc)
{
	int n, m, s;
	cin>>n>>m;
	vector<vpt> adj(n);
	vi u(m), v(m), w(m);
	map<pt, int>  b;
	f(i, 0, m)
	{
		cin>>u[i]>>v[i]>>w[i];
		u[i]--;
		v[i]--;
		adj[u[i]].pb({v[i], w[i]});
		adj[v[i]].pb({u[i], w[i]});
		b[{u[i], v[i]}] = i;
		b[{v[i], u[i]}] = i;
	}
	cin>>s;
	s--;
	// bfs(b, adj, s);
	ll sum = 0;
	Dijkstra d(n);
	vi ans;
	vi p = d.calculateShortestDis(adj, s, b, w);
	f(i, 0, p.size())
	{
		if(i != s)
		{
			int index = b[{p[i], i}];
			sum += w[index];
			ans.pb(index + 1);
		}
	}
	cout<<sum<<endl;
	f(i, 0, ans.size())
	{
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

