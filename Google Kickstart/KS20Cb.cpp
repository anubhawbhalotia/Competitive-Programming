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
typedef map<pt, bool> mpti;
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
#define watch1(x) cout <<(#x)<<" = "<<(x)<< endl
#define watch2(x, y) cout<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<endl
#define watch3(x, y, z) cout<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<" "<<\
	(#z)<<" = "<<z<<endl
#define log1(x) cout<<x<<endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MOD = 998244353;  
int dx[] = {-1, 0, 1, 0} , dy[] = {0, 1, 0, -1};
int buildGraph(vs &a, mpti &m, int &r, int &c)
{
	vvb flag(r, vb(c, 0));
	vb b(120, 0);
	f(i, 0, r)
	{
		f(j, 0, c)
		{
			if(flag[i][j] == 0)
			{	
				char val = a[i][j];
				if(b[val] == 1)
					return 0;
				queue <pt> q;
				q.push({i, j});
				flag[i][j] = 1;
				b[val] = 1;
				if(i + 1 < r)
				{
					if(a[i + 1][j] != val)
					{
						m[{val, a[i + 1][j]}] = 1;
					}
				}
				while(!q.empty())
				{
					pt z = q.front();
					q.pop();
					f(k, 0, 4)
					{
						int x = z.X + dx[k];
						int y = z.Y + dy[k];
						if(x >= 0 && x < r && y >= 0 && y < c)
						{
							if(a[x][y] == val && flag[x][y] == 0)
							{
								q.push({x, y});
								flag[x][y] = 1;
								if(x + 1 < r)
								{
									if(a[x + 1][y] != val)
									{
										m[{val, a[x + 1][y]}] = 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 1;
}
int dfs(char x, int d, mpti &m, vi &flag, string &ans)
{
	flag[x] = d;
	for(char i = 'A'; i <= 'Z'; i++)
	{
		if(m[{x, i}] == 1)
		{
			if(flag[i] == 0)
			{
				if(dfs(i, d, m, flag, ans) == 0)
					return 0;
			}
			else if(flag[i] == d)
				return 0;
		}
	}
	flag[x] = 1;
	ans += x;
	return 1;
}
string solution(int tc)
{
	int r, c;
	cin>>r>>c;
	vs a(r);
	vb p(120 , 0);
	int count = 0;
	f(i, 0, r)
	{
		cin>>a[i];
		for(auto j : a[i])
		{
			if(p[j] == 0)
			{
				count++;
				p[j] = 1;
			}
		}
	}
	mpti m;
	if(buildGraph(a, m, r, c))
	{
		vi in(120, 0);
		for(auto i : m)
		{
			in[i.X.Y]++;
		}
		vi flag(120, 0);
		int d = 1;
		string ans = "";
		for(int i = 'A'; i <= 'Z'; i++)
		{
			if(in[i] == 0 && p[i] == 1)
			{
				d++;
				if(dfs(i, d, m, flag, ans) == 0)
					return "-1";
			}
		}

		if(ans.length() < count)
			return "-1";
		return ans;
	}
	else
	{
		return "-1";
	}
}
void testCase()
{
	int tc = 1;
	cin>>tc;
	f(i, 0, tc)
	{
		// solution(i + 1);
		cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   