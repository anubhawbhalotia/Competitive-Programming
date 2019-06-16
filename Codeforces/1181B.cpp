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
string sa(string a, string b)
{
	int x = a.length() - 1, y = b.length() - 1, carry = 0;
	string ans = "";
	while(x >= 0 && y >= 0)
	{
		int temp = (a[x] - 48) + (b[y] - 48) + carry;
		ans += (char)((temp%10) + 48);
		carry = temp / 10;
		x--;
		y--;
	}
	while(x >= 0)
	{
		int temp = (a[x] - 48) + carry;
		ans += (char)((temp % 10) + 48);
		carry = temp / 10;
		x--;
	}
	while(y >= 0)
	{
		int temp = (b[y] - 48) + carry;
		ans += (char)((temp % 10) + 48);
		carry = temp / 10;
		y--;
	}
	if(carry)
		ans += (char)(carry + 48);
	reverse(all(ans));
	return ans;
}
int cmp(string a, string b)
{
	if(a.length() < b.length())
		return -1;
	if(a.length() > b.length())
		return 1;
	f(i, 0, a.length())
	{
		if(a[i] != b[i])
		{
			if(a[i] < b[i])
				return -1;
			if(a[i] > b[i])
				return 1;
		}
	}
	return 0;
}
void solution(int t)
{
	int l;
	cin>>l;
	string n, g;
	cin>>n;
	int st = max(1, (l / 2) - 1);
	int mid1 = max(1, (l / 2));
	int mid2 = max(1, (l+1) / 2);
	string ans(l + 1, '9');
	while(st >= 1)
	{
		if(n[st] == '0')
			st--;
		else
			break;
	}
	if(st > 0)
	{
		g = sa(n.substr(0, st), n.substr(st, l - st));
		if(cmp(g, ans) == -1)
			ans = g;
	}
	st--;
	if(st > 0 && n[st] != '0')
	{
		g = sa(n.substr(0, st), n.substr(st, l - st));
		if(cmp(g, ans) == -1)
			ans = g;
	}
	if(n[mid1] != '0')
	{
		g = sa(n.substr(0, mid1), n.substr(mid1, l - mid1));
		if(cmp(g, ans) == -1)
			ans = g;
	}
	if(n[mid2] != '0')
	{
		g = sa(n.substr(0, mid2), n.substr(mid2, l - mid2));
		if(cmp(g, ans) == -1)
			ans = g;
	}
	st = mid2 + 1;
	while(st < l)
	{
		if(n[st] == '0')
			st++;
		else
			break;
	}
	if(st < l)
	{
		g = sa(n.substr(0, st), n.substr(st, l - st));
		if(cmp(g, ans) == -1)
			ans = g;
	}
	st++;
	if(st < l && n[st] != '0')
	{
		g = sa(n.substr(0, st), n.substr(st, l - st));
		if(cmp(g, ans) == -1)
			ans = g;
	}
	cout<<ans<<endl;
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