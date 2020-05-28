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
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
#define watch1(x) cerr <<(#x)<<" = "<<(x)<< endl
#define watch2(x, y) cerr<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<endl
#define watch3(x, y, z) cerr<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<" "<<\
	(#z)<<" = "<<z<<endl
#define watchContainer1(x) for(auto i : x){cerr<<i<<" ";}cout<<endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',',\
	 ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); \
	err(_it, args); }
#define log1(x) cout<<x<<endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MOD = 998244353;  
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int traverse(vi &flag, int d, vector<vpt> &adj, vi &p, si &incl)
{
	queue<int> q;
	for(auto i : p)
	{
		if(flag[i] == 0)
		{
			flag[i] = 1;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int z = q.front();
		q.pop();
		for(auto i : adj[z])
		{
			if(flag[i.X] == 0)
			{
				flag[i.X] = 1;
				q.push(i.X);
				incl.insert(i.Y);
			}
		}		
	}
	return 1;
}
int solution(int tc)
{
	int n, k, d;
	cin>>n>>k>>d;
	vi p(k);
	f(i, 0, k)
	{
		cin>>p[i];
		p[i]--;
	}	
	vector<vpt> adj(n);
	int x, y;
	f(i, 0, n - 1)
	{
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb({y, i});
		adj[y].pb({x, i});
	}
	vi flag(n, 0);
	si incl;
	traverse(flag, d, adj, p , incl);
	vi ans;
	f(i, 0, n - 1)
	{
		if(incl.find(i) == incl.end())
		{
			ans.pb(i);
		}
	}
	log1(ans.size());
	for(auto i : ans)
	{
		cout<<i + 1<<" ";
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
