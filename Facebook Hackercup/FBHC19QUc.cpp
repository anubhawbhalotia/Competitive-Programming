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
string s;
map <string, char> m;
void build(vector<vector<int>> &opList, vi &pt)
{
	int l = -1;
	f(i, 0, s.length())
	{
		if(s[i] == '(')
			l++;
		else if(s[i] == ')')
			l--;
		else if(s[i] == '&' || s[i] == '|' || s[i] == '^')
			opList[l].pb(i);
	}
}
char solve(int l, int r, int lv, vector<vector<int>> &opList, vi &pt)
{
	if(l == r)
		return s[l];
	int opIndex = opList[lv][pt[lv]];
	char op = s[opIndex];
	pt[lv]++;
	char lhs = solve(l + 1, opIndex - 1, lv + 1, opList, pt);
	char rhs = solve(opIndex + 1, r - 1, lv + 1, opList, pt);
	string key = "";
	key += lhs;
	key += op;
	key += rhs;
	if(m.find(key) == m.end())
		reverse(all(key));
	return m[key];
}
void solution(int t)
{
	cin>>s;
	vector<vector<int>> opList(300);
	vi pt(300, 0);
	build(opList, pt);
	int ans = 0;
	char val = solve(0, s.length() - 1, 0, opList, pt);	
	if(val == 'X' || val == 'x')
		ans++;
	cout<<"Case #"<<t<<": "<<ans<<endl;

}
void testCase()
{
	int t = 1;
	cin>>t;
	m["0&0"] = '0';
	m["0|0"] = '0';
	m["0^0"] = '0';

	m["1&0"] = '0';
	m["1|0"] = '1';
	m["1^0"] = '1';

	m["1&1"] = '1';
	m["1|1"] = '1';
	m["1^1"] = '0';

	m["x&0"] = '0';
	m["x|0"] = 'x';
	m["x^0"] = 'x';

	m["x&1"] = 'x';
	m["x|1"] = '1';
	m["x^1"] = 'X';

	m["X&0"] = '0';
	m["X|0"] = 'X';
	m["X^0"] = 'X';

	m["X&1"] = 'X';
	m["X|1"] = '1';
	m["X^1"] = 'x';
	
	m["x&x"] = 'x';
	m["x|x"] = 'x';
	m["x^x"] = '0';

	m["X&X"] = 'X';
	m["X|X"] = 'X';
	m["X^X"] = '0';

	m["X&x"] = '0';
	m["X|x"] = '1';
	m["X^x"] = '1';
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