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
int test;
class Dijkstra
{
private:
	vi shortestDis;
	int n;	//n => number of nodes in the graph
public:
	Dijkstra(int z)
	{
		n = z;
		shortestDis.resize(n, 2e9);
	}
	vi calculateShortestDis(vector<vpt> &adj, int source, vector<mi> &t)
	{
		vi vis(n, 0);
		set <pt> notIncl;
		shortestDis[source] = 0;
		int weight;
		while(t[source].find(shortestDis[source]) != t[source].end())
		{
			shortestDis[source]++;
		}
		f(i, 0, n)
		{
			notIncl.insert({shortestDis[i], i});
		}
		pt first;
		while(!notIncl.empty())
		{
			first = *(notIncl.begin());
			vis[first.Y] = 1;
			notIncl.erase(notIncl.begin());
			for(auto i : adj[first.Y])
			{
				if(vis[i.X] == 0)
				{
					weight = i.Y + shortestDis[first.Y];
					if(i.X != n - 1)
					{
						if(t[i.X].find(weight) != t[i.X].end())
						{
							weight = t[i.X][weight];
						}
					}
					if(weight < shortestDis[i.X])
					{
						notIncl.erase({shortestDis[i.X], i.X});
						shortestDis[i.X] = weight;
						notIncl.insert({weight, i.X});
					}
				}
			}
		}
		return shortestDis;
	}
};
int solution(int tc)
{
	int n, m;
	cin>>n>>m;
	vector<vpt> adj(n);
	vi a(m), b(m), c(m);
	f(i, 0, m)
	{
		cin>>a[i]>>b[i]>>c[i];
		a[i]--;
		b[i]--;
		adj[a[i]].pb({b[i], c[i]});
		adj[b[i]].pb({a[i], c[i]});
	}
	vector<mi> t(n);
	int x, y;
	stack<int> s;
	f(i, 0, n)
	{
		cin>>x;
		int temp;
		f(j, 0, x)
		{
			cin>>y;
			if(!s.empty())
			{
				if(s.top() + 1 != y)
				{
					temp = s.top() + 1;
					while(!s.empty())
					{
						t[i][s.top()] = temp;
						s.pop();
					}
				}
			}
			s.push(y);
		}
		if(!s.empty())
		{
			temp = s.top() + 1;
			while(!s.empty())
			{
				t[i][s.top()] = temp;
				s.pop();
			}
		}
	}
	Dijkstra d(n);
	vi dis = d.calculateShortestDis(adj, 0, t);
	if(dis[n - 1] != 2e9)
		cout<<dis[n - 1]<<endl;
	else
		cout<<"-1"<<endl;
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

