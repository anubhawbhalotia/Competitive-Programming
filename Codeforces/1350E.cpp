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
int dx[] = {-1, 0, 1, 0} , dy[] = {0, 1, 0, -1};
vvi markCluster(vs &a)
{
	int n = a.size(), m = a[0].length();
	queue<pt> q;
	vvb flag(n, vb(m, 0));
	vvi ans(n, vi(m, 0));
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			if(flag[i][j] == 0)
			{
				int incl = 0;
				queue <pt> q;
				q.push({i, j});
				flag[i][j] = 1;
				while(!q.empty())
				{
					pt z = q.front();
					q.pop();
					f(k, 0, 4)
					{
						int x = z.X + dx[k];
						int y = z.Y + dy[k];
						if(x >= 0 && x < n && y >= 0 && y < m)
						{
							if(flag[x][y] == 0 && a[x][y] == a[i][j])
							{
								q.push({x, y});
								flag[x][y] = 1;
								incl = 1;
								ans[x][y] = 1;
							}
						}
					}
				}
				if(incl)
					ans[i][j] = 1;
			}
		}
	}
	return ans;
}
int findShortestDis(vvi &b)
{
	int n = b.size(), m = b[0].size();
	queue <pt> q;
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			if(b[i][j] == 1)
			{
				q.push({i, j});	
			}
		}
	}
	int dis = 2;
	while(!q.empty())
	{
		int sz = q.size();
		while(sz--)
		{
			pt z = q.front();
			q.pop();
			f(k, 0, 4)
			{
				int x = z.X + dx[k];
				int y = z.Y + dy[k];
				if(x >= 0 && x < n && y >= 0 && y < m)
				{
					if(b[x][y] == 0)
					{
						b[x][y] = dis;
						q.push({x, y});
					}
				}
			}
		}
		dis++;
	}
	return 1;
}
int solution(int tc)
{
	int n, m, t;
	cin>>n>>m>>t;
	vs a(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	vvi b = markCluster(a);
	findShortestDis(b);
	int x, y;
	ll p;
	vi ans;
	while(t--)
	{
		cin>>x>>y>>p;
		x--;
		y--;
		if(b[x][y] == 0 || p < b[x][y])
		{
			ans.pb(a[x][y] - 48);
		}
		else
		{
			p -= ((ll)b[x][y] - (ll)1);
			if(p % 2 == 0)
				ans.pb(a[x][y] - 48);
			else
				ans.pb(1 - (a[x][y] - 48));
		}
	}
	for(auto i : ans)
	{
		cout<<i<<endl;
	}
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

