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
typedef vector<pi> vpi;
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
#define all(v) v.begin(), v.end()
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
class dsu {
	map <pi, pi> n2k;
public:
	dsu(pi a)
	{
		n2k[a] = a;
	}
	pi findRoot(pi a)
	{
		stack <pi> s;
		while(n2k[a] != a)
		{
			s.push(a);
			a = n2k[a];
		}
		while(!s.empty())
		{
			n2k[s.top()] = a;
			s.pop();
		}
		return a;
	}
	pi un(pi a, pi b)
	{
		n2k[b] = findRoot(a);
	}
	int insert(pi a)
	{
		n2k[a] = a;
	}
	bool isPresent(pi a)
	{
		if(n2k.find(a) == n2k.end())
			return false;
		else
			return true;
	}
};
void solve(int t)
{
	int n, r, c, sr, sc;
	string p;
	cin>>n>>r>>c>>sr>>sc;
	cin>>p;
	pi curr = {sr, sc}, last;
	dsu ns(curr), we(curr);
	map <pi, vpi> box_ns = {{curr, {{sr-1, sc}, {sr+1, sc}}}};
	map <pi, vpi> box_we = {{curr, {{sr, sc-1}, {sr, sc+1}}}};
	map <char, pi> conv = {
		{'N', {-1, 0}}, {'S', {1, 0}}, {'W', {0, -1}},{'E', {0, 1}}
	};
	map <char, int> conv2 = {{'N', 0}, {'S', 1}, {'W', 0}, {'E', 1}};
	f(i, 0, p.size())
	{
		last = curr;
		curr += conv[p[i]];
		if(p[i] == 'N' || p[i] == 'S')
		{
			while(ns.isPresent(curr))
			{
				box_ns[ns.findRoot(curr)][0].fi = 
				min(box_ns[ns.findRoot(curr)][0].fi,
					box_ns[ns.findRoot(last)][0].fi);
				box_ns[ns.findRoot(curr)][1].fi = 
				max(box_ns[ns.findRoot(curr)][1].fi,
					box_ns[ns.findRoot(last)][1].fi);
				ns.un(curr, last);
				last = curr;
				curr = box_ns[ns.findRoot(curr)][conv2[p[i]]];
			}
			ns.insert(curr);
			ns.un(last, curr);
			box_ns[ns.findRoot(curr)][conv2[p[i]]] =
				box_ns[ns.findRoot(curr)][conv2[p[i]]] + conv[p[i]];
		}
		else
		{
			while(we.isPresent(curr))
			{
				box_we[we.findRoot(curr)][0].se = 
					min(box_we[we.findRoot(curr)][0].se,
						box_we[we.findRoot(last)][0].se);
				box_we[we.findRoot(curr)][1].se = 
				max(box_we[we.findRoot(curr)][1].se,
					box_we[we.findRoot(last)][1].se);
				we.un(curr, last);
				last = curr;
				curr = box_we[we.findRoot(curr)][conv2[p[i]]];
			}
			we.insert(curr);
			we.un(last, curr);
			box_we[we.findRoot(curr)][conv2[p[i]]].fi += conv[p[i]].fi;
			box_we[we.findRoot(curr)][conv2[p[i]]].se += conv[p[i]].se;
		}
		if(ns.isPresent(curr) == false)
		{
			ns.insert(curr);
			box_ns[ns.findRoot(curr)] = {
				{curr.fi - 1, curr.se}, {curr.fi + 1, curr.se}
			};
		}

		if(we.isPresent(curr) == false)
		{
			we.insert(curr);
			box_we[we.findRoot(curr)] = {
				{curr.fi, curr.se - 1}, {curr.fi, curr.se + 1}
			};
		}
	}
	cout<<"Case #"<<t<<": "<<curr.fi<<" "<<curr.se<<endl;
}
void testCase()
{
	int t;
	cin>>t;
	f(i, 1, t + 1)
	{
		solve(i);
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
   	testCase(); 
}  
