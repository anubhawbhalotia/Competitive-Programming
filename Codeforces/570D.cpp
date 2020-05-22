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
int dfs(int curr, int dep, int &c, vi &in, vi &ot, vector<vpt> &adj, vvi &nl)
{
	in[curr] = c++;
	nl[dep].pb(curr);
	for(auto i : adj[curr])
	{
		dfs(i.X, dep + 1, c, in, ot, adj, nl);
	}
	ot[curr] = c++;
	return 1;
}		
int bsG(int x, int d, vi &in, vi &ot, vvi &nl, int &n)
{
	if(d > n)
		return -1;
	if(nl[d].empty())
		return -1;
	int l = 0, r = nl[d].size() - 1;
	while(l < r)
	{
		int mid = ((l + r) / 2);
		int z = nl[d][mid];
		if(in[z] >= in[x])
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	int z = nl[d][l];
	if(in[z] >= in[x])
		return l;
	return -1;
}
int bsL(int x, int d, vi &in, vi &ot, vvi &nl, int &n)
{
	if(d > n)
		return -1;
	if(nl[d].empty())
		return -1;
	int l = 0, r = nl[d].size() - 1;
	while(l < r)
	{
		int mid = ((l + r) / 2) + 1;
		int z = nl[d][mid];
		if(in[z] < ot[x])
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	int z = nl[d][l];
	if(in[z] < ot[x])
		return l;
	return -1;
}
int bitwiseGetCountSetBit(int a)
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
	int n, m;
	cin>>n>>m;
	int p;
	vector<vpt> adj(n);
	f(i, 1, n)
	{
		cin>>p;
		adj[--p].pb({i, 0});
	}
	string s;
	cin>>s;
	vvi nl(n + 1), pref(n + 1);	// list of all nodes at depth i = nl[i]
	int c = 0;	//variable to track in and out timer
	vi in(n), ot(n);
	dfs(0, 1, c, in, ot, adj, nl);
	//building prefix array
	f(i, 1, nl.size())
	{
		f(j, 0, nl[i].size())
		{
			if(j > 0)
			{
				pref[i].pb(pref[i][j - 1] ^ 1<<(s[nl[i][j]] - 97));
			}
			else
			{
				pref[i].pb(1<<(s[nl[i][j]] - 97));
			}
		}
	}
	int x, y;
	while(m--)
	{
		cin>>x>>y;	// x = vertex, y = depth
		x--;
		int l = bsG(x, y, in, ot, nl, n);
		int r = bsL(x, y, in, ot, nl, n);
		if(l != -1 && r != -1 && l <= r)
		{
			int freq = pref[y][r];
			if(l > 0)
			{
				freq = pref[y][r] ^ pref[y][l - 1];
			}
			if(bitwiseGetCountSetBit(freq) > 1)
				log1("No");
			else
				log1("Yes");
		}
		else
		{
			log1("Yes");
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
