#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
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
#define x first
#define y second
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
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}   
vector<vector<bool>> g;
set<int> s;
bool boxCheck(int c)
{
	if((g[0][c - 1] == false && g[0][c] == false) || (g[1][c - 1] == false && g[1][c] == false))
	{
		auto it = s.lb(c - 1);
		if(it != s.end())
		{
			if(*it == c - 1)
			{
				s.erase(s.lb(c - 1));
			}
		}
	}
	else
	{
		s.insert(c - 1);
	}
}
void printGrid(int n)
{
	f(i, 0, 2)
	{
		f(j, 0, n)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
}
void solution(int t)
{
	int n, q, r, c;
	cin>>n>>q;
	g.resize(2, vector<bool>(n, false));
	f(i, 0, q)
	{
		cin>>r>>c;
		r--;
		c--;
		g[r][c] = (g[r][c] == true) ? false : true;
		// printGrid(n);
		if(c == 0)
		{
			boxCheck(c + 1);
		}
		else if(c == n - 1)
		{
			boxCheck(c);
		}	
		else
		{
			boxCheck(c);
			boxCheck(c + 1);
		}
		if(s.empty())
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}

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