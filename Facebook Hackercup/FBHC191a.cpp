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
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
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
#define fi first
#define se second
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
int n, m;
vvi w(51, vi(51, INT_MAX));
vi x(1001), y(1001), z(1001);
void dijkstraAllPair(vvi &sp, vvi &g)
{
	pii t;
	f(src, 1, n + 1)
	{
		set <pii> s;
		sp[src][src] = 0;
		f(i, 1, src)
			s.insert({INT_MAX, i});
		s.insert({0, src});
		f(i, src + 1, n + 1)
			s.insert({INT_MAX, i});
		vector <bool> flag(n + 1, false);
		while(!s.empty())
		{
			t = *(s.begin());
			s.erase(s.begin());
			flag[t.se] = true;
			if(t.fi == INT_MAX)
				break;
			f(i, 0, g[t.se].size())
			{
				if(flag[g[t.se][i]])
					continue;
				if(sp[src][g[t.se][i]] > sp[src][t.se] + w[t.se][g[t.se][i]])
				{
					s.erase(s.lb({sp[src][g[t.se][i]], g[t.se][i]}));
					sp[src][g[t.se][i]] = sp[src][t.se] + w[t.se][g[t.se][i]];
					s.insert({sp[src][g[t.se][i]], g[t.se][i]});
				}
			}
		}	
	}
}
bool isCorrect(vvi &sp, vi &x, vi &y, vi &z)
{
	f(i, 0, m)
	{
		if(sp[x[i]][y[i]] != z[i])
			return false;
	}
	return true;
}
void solution(int t)
{
	cin>>n>>m;
	vvi g(n + 1);	//adjacency list
	vvi sp(n + 1, vi(n + 1, INT_MAX));		//shortest path matrix
	f(i, 0, m)
	{
		cin>>x[i]>>y[i]>>z[i];
		w[x[i]][y[i]] = z[i];
		w[y[i]][x[i]] = z[i];
		g[x[i]].pb(y[i]);
		g[y[i]].pb(x[i]);
	}
	dijkstraAllPair(sp, g);
	cout<<"Case #"<<t<<": ";
	if(isCorrect(sp, x, y, z))
	{
		cout<<m<<endl;
		f(i, 0, m)
			cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
	}
	else
		cout<<"Impossible"<<endl;
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