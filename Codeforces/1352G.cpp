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
void disp(int l, int r, map<int, vi> &m)
{
	for(auto i : m[r - l + 1])
	{
		cout<<l + i - 1<<" ";
	}
}
int solution(int tc, map <int, vi> &m)
{
	int n;
	cin>>n;
	if(n <= 3)
	{
		cout<<"-1"<<endl;
		return 1;
	}
	if(n % 8 >= 4 || n % 4 == 0)
	{
		int i = 0;
		while(i < n)
		{
			disp(i + 1, min(i + 8, n), m);
			i = min(i + 8, n);
		}
		cout<<endl;
	}
	else
	{
		int r = n - (n % 8) - 8;
		int i = 0;
		while(i < r)
		{
			disp(i + 1, i + 8, m);
			i += 8;
		}
		int x = n - r - 4;
		disp(i + 1, i + x, m);
		i += x;
		disp(i + 1, i + 4, m);
		cout<<endl;
	}
	return 1;
}
void testCase()
{
	int tc = 1;
	cin>>tc;
	map <int, vi> m;
	m[4] = {3, 1, 4, 2};
	m[5] = {3, 1, 4, 2, 5};
	m[6] = {3, 5, 1, 4, 2, 6};
	m[7] = {3, 6, 2, 5, 1, 4, 7};
	m[8] = {1, 4, 8, 5, 2, 6, 3, 7};
	f(i, 0, tc)
	{
		solution(i + 1, m);
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

