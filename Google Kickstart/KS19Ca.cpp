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
#define all(v) beg(v), en(v)
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
const int MOD = 998244353;
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
pi solve()
{
	int n, r, c, sr, sc;
	map <pi, vpi> box_ns, box_we;
	string p;
	cin>>n>>r>>c>>sr>>sc;
	cin>>p;
	pi curr = mp(sr, sc), last;
	dsu ns(curr), we(curr);
	box_ns[ns.findRoot(curr)].pb(mp(sr-1, sc));
	box_ns[ns.findRoot(curr)].pb(mp(sr+1, sc));
	box_we[we.findRoot(curr)].pb(mp(sr, sc-1));
	box_we[we.findRoot(curr)].pb(mp(sr, sc+1));
	map <char, pi> conv;
	conv['N'] = mp(-1, 0);
	conv['S'] = mp(1, 0);
	conv['W'] = mp(0, -1);
	conv['E'] = mp(0, 1);
	map <char, int> conv2;
	conv2['N'] = 0;
	conv2['S'] = 1;
	conv2['W'] = 0;
	conv2['E'] = 1;
	f(i, 0, p.size())
	{
		// cout<<"last = "<<curr.fi<<" "<<curr.se<<" ";
		last = curr;
		curr.fi += conv[p[i]].fi;
		curr.se += conv[p[i]].se;
		// cout<<"curr = "<<curr.fi<<" "<<curr.se<<endl;
		if(p[i] == 'N' || p[i] == 'S')
		{
			while(ns.isPresent(curr))
			{
				// cout<<"ns.isPresent(curr) "<<ns.isPresent(curr)<<endl;
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
			box_ns[ns.findRoot(curr)][conv2[p[i]]].fi += conv[p[i]].fi;
			box_ns[ns.findRoot(curr)][conv2[p[i]]].se += conv[p[i]].se;
			// cout<<"Inside ";
			// cout<<"last = "<<curr.fi<<" "<<curr.se<<" ";
			// cout<<"curr = "<<curr.fi<<" "<<curr.se<<endl;
		}
		else
		{
			while(we.isPresent(curr))
			{
				// cout<<"we.isPresent(curr) "<<we.isPresent(curr)<<endl;
				// cout<<"before ";
				// cout<<we.findRoot(curr).fi<<" "<<we.findRoot(curr).se<<" "<<
				// 	box_we[we.findRoot(curr)][0].se<<" "<<box_we[we.findRoot(curr)][1].se<<endl;
				// cout<<we.findRoot(last).fi<<" "<<we.findRoot(last).se<<" "<<
				// 	box_we[we.findRoot(last)][0].se<<" "<<box_we[we.findRoot(last)][1].se<<endl;
				box_we[we.findRoot(curr)][0].se = 
					min(box_we[we.findRoot(curr)][0].se,
						box_we[we.findRoot(last)][0].se);
				box_we[we.findRoot(curr)][1].se = 
				max(box_we[we.findRoot(curr)][1].se,
					box_we[we.findRoot(last)][1].se);
				// cout<<"after ";
				// cout<<box_we[we.findRoot(curr)][0].se<<" "<<box_we[we.findRoot(curr)][1].se<<endl;
				we.un(curr, last);
				last = curr;
				curr = box_we[we.findRoot(curr)][conv2[p[i]]];
			}
			we.insert(curr);
			we.un(last, curr);
			box_we[we.findRoot(curr)][conv2[p[i]]].fi += conv[p[i]].fi;
			box_we[we.findRoot(curr)][conv2[p[i]]].se += conv[p[i]].se;
			// cout<<"Inside ";
			// cout<<"last = "<<curr.fi<<" "<<curr.se<<" ";
			// cout<<"curr = "<<curr.fi<<" "<<curr.se<<endl;
			// cout<<we.findRoot(curr).fi<<" "<<we.findRoot(curr).se<<" "<<
					// box_we[we.findRoot(curr)][0].se<<" "<<box_we[we.findRoot(curr)][1].se<<endl;
			// cout<<we.findRoot(last).fi<<" "<<we.findRoot(last).se<<" "<<
				// box_we[we.findRoot(last)][0].se<<" "<<box_we[we.findRoot(last)][1].se<<endl;

		}
		if(ns.isPresent(curr) == false)
		{
			ns.insert(curr);
			box_ns[ns.findRoot(curr)].pb(mp(curr.fi - 1, curr.se));
			box_ns[ns.findRoot(curr)].pb(mp(curr.fi + 1, curr.se));
		}
		if(we.isPresent(curr) == false)
		{
			we.insert(curr);
			box_we[we.findRoot(curr)].pb(mp(curr.fi, curr.se - 1));
			box_we[we.findRoot(curr)].pb(mp(curr.fi, curr.se + 1));
		}
	}
	return curr;
}
void testCase()
{
	int t;
	cin>>t;
	f(i, 1, t + 1)
	{
		pi ans = solve();
		cout<<"Case #"<<i<<": "<<ans.fi<<" "<<ans.se<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
   	testCase(); 
}  
