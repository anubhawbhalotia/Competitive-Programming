#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
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
#define fi first
#define se second
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
string s[500];
int n, m;
int countAll(int r, int c)
{
	int a = 1;
	int t = r - 1;
	while(t >= 0)
	{
		if(s[t--][c] != '*')
			break;
		a++;
	}
	t = r + 1;
	while(t < n)
	{
		if(s[t++][c] != '*')
			break;
		a++;
	}
	t = c - 1;
	while(t >= 0)
	{
		if(s[r][t--] != '*')
			break;
		a++;
	}
	t = c + 1;
	while(t < m)
	{
		if(s[r][t++] != '*')
			break;
		a++;
	}
	return a;
}
void solution(int t)
{
	int c = 0;
	cin>>n>>m;
	f(i, 0, n)
	{
		cin>>s[i];
		f(j, 0, m)
		{
			if(s[i][j] == '*')
				c++;
		}
	}	
	f(i, 1, n - 1)
	{
		f(j, 1, m - 1)
		{
			if(s[i][j] == '*' && s[i-1][j] == '*' && s[i][j - 1] == '*'
				&& s[i + 1][j] == '*' && s[i][j+1] == '*')
			{
				int ans = countAll(i, j);
				if(ans == c)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
				return ;
			}
		}
	}
	cout<<"NO"<<endl;
	return ;
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