#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
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
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}  
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
void solution(int t)
{
	int n, m, a, b;
	cin>>n>>m;
	vector <pt> u, v;
	f(i, 0, m)
	{
		cin>>a>>b;
		if(b)
		{
			u.pb({a, i});	//in mst
		}
		else
		{
			v.pb({a, i});
		}
	}
	sort(all(u));
	sort(all(v));
	int x = v.size() - 1;
	vector <pt> ans(m);
	fre(i, n - 2, 0)
	{
		ans[u[i].Y] = {i + 1, i};
		int z = i - 1;
		while(x >= 0 && v[x].X >= u[i].X && z >= 0)
		{
			ans[v[x--].Y] = {i + 1, z--};
		}
	}
	if(x == -1)
	{
		f(i, 0, m)
		{
			cout<<ans[i].X + 1<<" "<<ans[i].Y + 1<<endl;
		}
	}
	else
	{
		cout<<"-1"<<endl;
	}
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
