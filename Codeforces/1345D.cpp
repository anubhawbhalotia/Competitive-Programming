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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
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
int traverse(vvc &a, vvi &vis, vi &x, vi &y, int &n, int &m, int r, int c)
{
	queue<pt> q;
	q.push({r, c});
	vis[r][c] = 1;
	int nr, nc;
	while(!q.empty())
	{
		pt z = q.front();
		q.pop();
		vis[z.X][z.Y] = 1;
		f(i, 0, 4)
		{
			nr = z.X + x[i];
			nc = z.Y + y[i];
			if(nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if(vis[nr][nc] == 0 && a[nr][nc] == '#')
				{
					// cout<<"nr nc = "<<nr<<" "<<nc<<endl;
					vis[nr][nc] = 1;
					q.push({nr, nc});
				}
			}
		}
	}
	return 1;
}
int solution(int tc)
{
	int n, m, t;
	cin>>n>>m;
	vvc a(n, vc(m));
	int b, w, bc = 0;
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			cin>>a[i][j];
			if(a[i][j] == '#')
				bc++;
		}
	}
	if(bc == 0)
		return 0;
	// f(i, 0, n)
	// {
	// 	f(j, 0, m)
	// 	{
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<endl;
	// }
	char prev;
	f(i, 0, n)
	{	
		b = 0;
		w = 0;
		bc = 0;
		prev = a[i][0];
		if(prev == '#')
			bc++;
		f(j, 1, m)
		{
			if(a[i][j] == '#')
				bc++;
			if(a[i][j] != prev)
			{
				if(prev == '#')
					b++;
				else
				{
					if(b != 0)
						w++;
				}
				prev = a[i][j];
				if(w == 1)
				{
					return -1;
				}
			}
		}
		if(bc == 0)
		{
			f(c, 0, m)
			{
				t = 0;
				f(r, 0, n)
				{
					if(a[r][c] == '#')
					{
						t++;
						break;
					}
				}
				if(t == 0)
					break;
			}
			if(t != 0)
				return -1;
		}
	}
	f(j, 0, m)
	{
		b = 0;
		w = 0;
		bc = 0; 
		prev = a[0][j];
		if(prev == '#')
			bc++;
		f(i, 1, n)
		{
			if(a[i][j] == '#')
				bc++;
			if(a[i][j] != prev)
			{
				if(prev == '#')
					b++;
				else
				{
					if(b != 0)
						w++;
				}
				prev = a[i][j];
				if(w == 1)
				{
					return -1;
				}
			}
		}
		if(bc == 0)
		{
			f(r, 0, n)
			{
				t = 0;
				f(c, 0, m)
				{	
					if(a[r][c] == '#')
					{
						t++;
						break;
					}
				}
				if(t == 0)
					break;
			}
			if(t != 0)
				return -1;
		}
	}
	vi x = {-1, 0, 1, 0};
	vi y = {0, 1, 0, -1};
	vvi vis(n, vi(m, 0));
	int ans = 0;
	f(i, 0, n)
	{
		f(j, 0, m)
		{
			if(vis[i][j] == 0 && a[i][j] == '#')
			{
				// cout<<i<<" "<<j<<endl;
				ans++;
				traverse(a, vis, x, y, n, m, i, j);
			}
			
		}
	}
	// cout<<ans<<endl;
	return ans;
}
void testCase()
{
	int tc = 1;
	// cin>>tc;
	f(i, 0, tc)
	{
		int ans = solution(i + 1);
		cout<<ans<<endl;
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

