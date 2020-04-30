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
class Dsu
{
private:
	vi a; 
	int n;
	int findRoot(int x)
	{
		vi temp;
		while(a[x] != x)
		{
			temp.pb(x);
			x = a[x];
		}
		for(auto i : temp)
		{
			a[i] = x;
		}
		return x;
	}
public:
	int build(int z)
	{
		n = (3 * z) + 1;
		a.resize(n);
		f(i, 0, n)
		{
			a[i] = i;
		}
		return 1;
	}
	int merge(int x, int y)
	{
		int temp = findRoot(y);
		a[findRoot(x)] = findRoot(y);
		findRoot(x);
		return temp;
	}
	bool isSameSet(int x, int y)
	{
		return findRoot(x) == findRoot(y);
	}
	int getSet(int x)
	{
		return findRoot(x);
	}
};
bool isPair(int a, int b)
{
	if(abs(a - b) == 1 && (min(a, b) % 2) == 0)
		return 1;
	return 0;
}
int getOpposite(int a)
{
	if(a % 2 == 0)
		return a + 1;
	else
		return a - 1;
}
int solution(int tc)
{
	int n, m;
	cin>>n>>m;
	vi r(n);
	f(i, 0, n)
	{
		cin>>r[i];
	}
	int x, y;
	vvi a(n);
	f(i, 0, m)
	{
		cin>>x;
		f(j, 0, x)
		{
			cin>>y;
			a[--y].pb(i);
		}
	}
	Dsu d;
	d.build(m);
	int maxSet = m, g, h;
	if(maxSet % 2 == 1)
		maxSet++;
	f(i, 0, n)
	{
		g = d.getSet(a[i][0]);
		h = d.getSet(a[i][1]);
		if(r[i] == 1)
		{	
			if(g != h)
			{
				if(g >= m && h >= m)
				{
					if(isPair(g, h))
					{
						return 0;
					}
					d.merge(h, g);
					d.merge(getOpposite(h), getOpposite(g));
				}
				else if(g >= m)
				{
					d.merge(a[i][1], g);
				}
				else if(h >= m)
				{
					d.merge(a[i][0], h);
				}
				else
				{
					d.merge(a[i][0], maxSet);
					d.merge(a[i][1], maxSet);
					maxSet+=2;
				}
			}
		}
		else
		{
			if(g == h)
			{
				return 0;
			}
			if(g >= m && h >= m)
			{	
				if(!isPair(g, h))
				{
					d.merge(h, getOpposite(g));
					d.merge(getOpposite(h), g);
				}
			}
			else if(g >= m)
			{
				d.merge(a[i][1], getOpposite(g));
			}
			else if(h >= m)
			{
				d.merge(a[i][0], getOpposite(h));
			}
			else
			{
				d.merge(a[i][0], maxSet);
				maxSet++;
				d.merge(a[i][1], maxSet);
				maxSet++;
			}
		}
	}
	return 1;	
}
void testCase()
{
	int tc = 1;
	// cin>>tc;
	map <bool, string> m;
	m[1] = "YES";
	m[0] = "NO";
	f(i, 0, tc)
	{
		bool ans = solution(i + 1);
		cout<<m[ans]<<endl;
		// //cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

