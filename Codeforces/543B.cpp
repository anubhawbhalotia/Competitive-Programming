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
class FloydWarshall
{
private:
	vvi shortestDis;
	int n;
public:
	FloydWarshall(int z)
	{
		n = z;
		shortestDis.resize(n, vi(n, 1e6));
	}
	int calculateShortestDis(vvi &w)
	{
		shortestDis = w;
		f(i, 0, n)
		{
			shortestDis[i][i] = 0;
		}
		f(k, 0, n)
		{
			f(i, 0, n)
			{
				f(j, 0, n)
				{
					shortestDis[i][j] = min(shortestDis[i][j], 
						shortestDis[i][k] + shortestDis[k][j]);
				}
			}
		}
		return 1;
	}
	int getDis(int x, int y)
	{
		return shortestDis[x][y];
	}
};
class BfsAllPairShortestDis
{
	// Given a connected, unweighted graph with no self loop and no multiple edges
private:
	vvi shortestDis;
	int n;	//number of node in the graph
public:
	BfsAllPairShortestDis(int z)
	{
		n = z;
		shortestDis.resize(n, vi(n, 1e5));
	}
	int calculateShortestDis(vector<vpt> &adj)
	{
		f(j, 0, n)
		{
			vb vis(n, 0);
			queue<int> q;
			shortestDis[j][j] = 0;
			q.push(j);
			vis[j] = 1;
			int dis = 1;
			while(!q.empty())
			{
				int sz = q.size();
				while(sz--)
				{
					int z = q.front();
					q.pop();
					for(auto i : adj[z])
					{
						if(vis[i.X] == 0)
						{
							vis[i.X] = 1;
							shortestDis[j][i.X] = dis;
							shortestDis[i.X][j] = dis;
							q.push(i.X);
						}
					}
				}
				dis++;
			}
		}
		return 1;
	}
	int getDis(int x, int y)
	{
		return shortestDis[x][y];
	}
};
int solution(int tc)
{
	int n, m;
	cin>>n>>m;
	vi a(m), b(m);
	vvi w(n, vi(n, 1e5));
	vector<vpt> adj(n);
	f(i, 0, m)
	{
		cin>>a[i]>>b[i];
		adj[--a[i]].pb({--b[i], 1});
		adj[b[i]].pb({a[i], 1});
		w[a[i]][b[i]] = 1;
		w[b[i]][a[i]] = 1;
	}
	int s1, t1, l1, s2, t2, l2;
	int d1, d2, d3, d4, d5, d6, d7;
	cin>>s1>>t1>>l1;
	cin>>s2>>t2>>l2;
	s1--;
	t1--;
	s2--;
	t2--;
	BfsAllPairShortestDis d(n);
	d.calculateShortestDis(adj);
	int ans = 1e5;
	if(d.getDis(s1, t1) <= l1 && d.getDis(s2, t2) <= l2)
		ans = max(0, m - (d.getDis(s2, t2) + d.getDis(s1, t1)));
	f(i, 0, n)
	{
		f(j, 0, n)
		{
			d1 = d.getDis(s1, i);
			d2 = d.getDis(s2, i);
			d3 = d.getDis(t1, j);
			d4 = d.getDis(t2, j);
			d5 = d.getDis(i, j);
			if((d1 + d3 + d5) <= l1 && (d2 + d4 + d5)<= l2)
			{
				ans = max(ans, max(0, m - (d1 + d2 + d3 + d4 + d5)));
			}
			d6 = d.getDis(t2, i);
			d7 = d.getDis(s2, j);
			if((d1 + d3 + d5) <= l1 && (d7 + d6 + d5) <= l2)
			{
				ans = max(ans, max(0, m - (d1 + d5 + d6 + d3 + d7)));	
			}

		}
	}
	if(ans == 1e5)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;
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

