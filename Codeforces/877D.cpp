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
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
#define watch1(x) cerr <<(#x)<<" = "<<(x)<< endl
#define watch2(x, y) cerr<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<endl
#define watch3(x, y, z) cerr<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<" "<<\
	(#z)<<" = "<<z<<endl
#define watchContainer1(x) for(auto i : x){cerr<<i<<" ";}cout<<endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',',\
	 ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); \
	err(_it, args); }
#define log1(x) cout<<x<<endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MOD = 998244353;  
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int dx[] = {-1, 0, 1, 0} , dy[] = {0, 1, 0, -1};
queue<pt> q;
int traverse(vector<string> &a, int k, int x1, int y1, int x2, int y2, 
	int n, int m)
{
	if(x1 == x2 && y1 == y2)
		return 0;
	q.push({x1, y1});
	vvi flag(n, vi(m, 0));
	flag[x1][y1] = 0;
	int dis = 1;
	while(!q.empty())
	{
		int sz = q.size();
		while(sz--)
		{
			pt z = q.front();
			q.pop();
			f(i, 0, 4)
			{
				pt temp = z;
				f(j, 0, k)
				{
					int r = temp.X + dx[i];
					int c = temp.Y + dy[i];
					if(r == x2 && c == y2)
						return dis;
					if(r >= 0 && r < n && c >= 0 && c < m)
					{
						if(flag[r][c] == 0 && a[r][c] == '.')
						{
							flag[r][c] = dis;
							q.push({r, c});
						}
						else if(flag[r][c] != dis)
							break;
					}
					else
						break;
					temp = {r, c};
				}
			}
		}
		dis++;
	}
	return -1;
}
int solution(int tc)
{	
	int n, m, k;
	cin>>n>>m>>k;
	vector<string> a(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	int x1, y1, x2, y2;
	cin>>x1>>y1>>x2>>y2;
	x1--;
	y1--;
	x2--;
	y2--;
	log1(traverse(a, k, x1, y1, x2, y2, n, m));
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
