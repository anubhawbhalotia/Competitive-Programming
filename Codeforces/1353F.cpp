#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ll solve(vvl &a, vvl &e, int &n, int &m)
{
	ll z;
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			if(i == 0 && j == 0)
			{
				e[i][j] = 0;
				continue;
			}
			z = i + j;
			e[i][j] = LLONG_MAX;
			if(j > 0)
			{
				if(a[i][j] >= (a[0][0] + z) && e[i][j - 1] != LLONG_MAX)
				{
					e[i][j] = e[i][j - 1] + (a[i][j] - a[0][0] - z);
				}
			}
			if(i > 0)
			{
				if(a[i][j] >= (a[0][0] + z) && e[i - 1][j] != LLONG_MAX)
				{
					e[i][j] = min(e[i][j], 
						e[i - 1][j] + a[i][j] - a[0][0] - z);
				}
			}
		}
	}
	return e[n - 1][m - 1];
}
int solution(int tc)
{
	int n, m;
	cin>>n>>m;
	vvl a(n, vl(m)), e(n, vl(m));
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			cin>>a[i][j];
		}
	}
	if(n == 1 && m == 1)
	{
		cout<<"0"<<endl;
		return 1;
	}
	ll st = -300, en = a[0][0], z = a[0][0], ans = 1e18;
	while(st < en)
	{
		ll mid = ((st + en + 1) / 2);
		a[0][0] = mid;
		ll y = solve(a, e, n, m);
		if(y >= 0 && y != LLONG_MAX)
		{
			st = mid;
			// ll temp = y + (z - mid);
		}
		else
		{
			en = mid - 1;
		}
	}
	a[0][0] = st;
	ll y = solve(a, e, n, m);
	ans = y + (z - st);
	cout<<ans<<endl;
	return 1;
}
void testCase()
{
	int tc = 1;
	cin>>tc;
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

