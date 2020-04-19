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
const ll MOD = 1000000000;
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
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
map <char, ptl> m; 
ll getModVal(ll a)
{
	a = (a + 10000000000) % 1000000000;
	return a;
}
ptl solve(int &x, string &s)
{
	ptl ans = {0, 0}, z;
	ll d;
	while(x < s.length())
	{
		if(s[x] >= '2' && s[x] <= '9')
		{
			d = s[x] - 48;
			x += 2;
			z = solve(x, s);
			ans.x = getModVal(ans.x + (d* z.x));
			ans.y = getModVal(ans.y + (d* z.y));
		}
		else if(s[x] == ')')
		{
			break;
		}
		else
		{
			ans.y = getModVal(ans.y + m[s[x]].x);
			ans.x = getModVal(ans.x + m[s[x]].y);
		}
		x++;
	}
	return ans;
}
void solution(int t)
{
	string s;
	cin>>s;
	int x = 0;
	ptl z = solve(x, s);
	cout<<"Case #"<<t<<": "<<z.x + 1<<" "<<z.y + 1<<endl;
}
void testCase()
{
	m['N'] = {-1, 0};
	m['S'] = {1, 0};
	m['W'] = {0, -1};
	m['E'] = {0, 1};
	int t = 1;
	cin>>t;
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