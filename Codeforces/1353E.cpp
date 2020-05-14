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
int solution(int tc)
{
	int n, k;
	cin>>n>>k;

	string s;
	cin>>s;

	int t = 0;
	f(i, 0, n)
	{
		if(s[i] == '1')
			t++;
	}
	
	map <char, int> m;
	m['1'] = -1;
	m['0'] = 1;
	
	int ans = INT_MAX;
	
	f(i, 0, k)
	{
		string b = "";
		int d = 0;
		for(int j = i; j < n; j += k)
		{
			b += s[j];
			if(s[j] == '1')
				d++;
		}
		
		// cout<<"b = "<<b<<"t = "<<t<<" d = "<<d<<endl;
		int l = b.length();
		vi pre(l, 0);
		if(b[0] == '1')
			pre[0] = 1;
		f(j, 1, l)
		{
			pre[j] = pre[j - 1];
			if(b[j] == '1')
				pre[j]++;
		}
		
		set <pt> a;
		int x = 0;
		f(j, 0, l)
		{
			int z = pre[l - 1] - pre[j];
			int y = j + 1 - pre[j];
			ans = min(ans, z + y + (t - d));
			y = pre[j];
			ans = min(ans, z + y + (t - d));
			if(!a.empty())
			{
				auto it = a.end();
				it--;
				y = pre[it->Y];
				y += ((j + 1 - pre[j]) - (it->Y + 1 - pre[it->Y]));
				ans = min(ans, z + y + (t - d));
			}
			x += m[b[j]];
			a.insert({x, j});
		}
	}
	if(ans == INT_MAX)
		ans = 0;
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

