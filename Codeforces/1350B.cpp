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
vvi getDivisors(int n)
{
	vvi d(n + 1);
	f(i, 1, n + 1)
	{
		for(int j = i; j < n + 1; j += i)
		{
			d[j].pb(i);
		}
	}
	return d;
}
int solution(int tc, vvi &d)
{
	int n;
	cin>>n;
	vi a(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	int x;
	vi DP(n + 1, 1);
	int ans = 1;
	f(i, 0, n)
	{
		x = i + 1;
		// cout<<"x = "<<x<<endl;
		for(auto j : d[x])
		{
			// cout<<"j = "<<j<<endl;
			if(j >= x)
				break;
			if(a[i] > a[j - 1])
			{
				DP[x] = max(DP[x], DP[j] + 1);
				// cout<<"DP updating "<<DP[x]<<endl;
				ans = max(ans, DP[x]);
			}
		}
	}
	cout<<ans<<endl;
	return 1;
}
void testCase()
{
	int tc = 1;
	cin>>tc;
	vvi d = getDivisors(100000);
	// cout<<"div found"<<endl;
	// f(i, 1, 5)
	// {
	// 	f(j, 0, d[i].size())
	// 	{
	// 		cout<<d[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	f(i, 0, tc)
	{
		solution(i + 1, d);
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

