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
vvi graph;
vi flag, p;
pt e;
int dia;
vi dfs(int node, int l)
{
	vvi m(2, vi(2, 0));
	int b = 0;
	f(i, 0, graph[node].size())
	{
		if(!flag[graph[node][i]])
		{
			b = 1;
			flag[graph[node][i]] = 1;
			vi temp = dfs(graph[node][i], l + 1);
			temp[0]++;
			if(temp[0] > m[1][0])
			{
				if(temp[0] > m[0][0])
				{
					m[1] = m[0];
					m[0] = temp;
				}
				else
				{
					m[1] = temp;
				}
			}
		}
	}
	if(!b)
	{
		m[0][1] = node;
	}
	if(m[0][0] + m[1][0] > dia)
	{
		dia = m[0][0] + m[1][0];
		e = mp(m[0][1], m[1][1]);
	}
	if(l + m[0][0] > dia)
	{
		dia = l + m[0][0];
		e = mp(1, m[0][1]);
	}
	return m[0];
}
void findDia()
{
	dia = 0;
	flag[1] = 1;
	dfs(1, 0);
}
bool findPath(int node)
{
	if(node == e.y)
	{
		p.pb(node);
		return 1;
	}
	f(i, 0, graph[node].size())
	{
		if(!flag[graph[node][i]])
		{
			flag[graph[node][i]] = 1;
			bool temp = findPath(graph[node][i]);
			if(temp == 1)
			{
				p.pb(node);
				return temp;
			}
		}
	}
	return false;
}
pt msBfs(int n)
{
	pt ans;
	f(i, 0, n + 1)
		flag[i] = 0;
	flag[e.x] = 1;
	findPath(e.x);
	vector <queue<int>> q(p.size());
	unordered_set <int> mark;
	f(i, 0, n + 1)
		flag[i] = 0;
	f(i, 0, p.size())
	{
		flag[p[i]] = 1;
		q[i].push(p[i]);
	}
	vi dis((int)p.size(), 0);
	int temp;
	while(mark.size() < p.size())
	{
		f(i, 0, p.size())
		{
			if(mark.find(i) == mark.end())
			{
				int sz = q[i].size();
				f(k, 0, sz)
				{
					temp = q[i].front();
					q[i].pop();
					f(j, 0, graph[temp].size())
					{
						if(!flag[graph[temp][j]])
						{
							flag[graph[temp][j]] = 1;
							q[i].push(graph[temp][j]);
						}
					}
				}
				if(q[i].empty())
				{
					mark.insert(i);
					if(dis[i] > ans.x)
					{
						ans = mp(dis[i], temp);
					}
				}
				else
				{
					dis[i]++;
				}
			}
		}	
	}
	return ans;
}
int findOtherNode(int n)
{
	f(i, 1, n + 1)
	{
		if(e.x != i && e.y != i)
			return i;
	}
}
void solution(int t)
{
	int n, a, b;
	cin>>n;
	graph.resize(n + 1);
	flag.resize(n + 1, 0);
	f(i, 0, n - 1)
	{
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	findDia();
	if(dia == n - 1)
	{	
		a = findOtherNode(n);
	}
	else
	{
		pt ans = msBfs(n);
		a = ans.y;
		dia += ans.x;
	}
	cout<<dia<<endl;
	cout<<e.x<<" "<<e.y<<" "<<a<<endl;
}
void testCase()
{
	int t = 1;
	// cin>>t;
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