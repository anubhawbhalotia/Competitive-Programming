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
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
string solution(int t)
{
	int n;
	cin>>n;
	vector<string> pref(n, ""), suff(n, "");
	string ans = "", a, yz = "";
	int max_pref = 0, max_suff = 0;
	f(i, 0, n)
	{
		cin>>a;
		int j = 0;
		while(j < a.length() && a[j] != '*')
		{
			pref[i] += a[j++];
		}
		if(pref[i].length() > pref[max_pref].length())
		{
			max_pref = i;
		} 	  	 	
		j++;
		int k = a.length() - 1;
		while(k >= 0 && a[k] != '*')
		{
			suff[i] += a[k--];
		}
		if(suff[i].length() > suff[max_suff].length())
		{
			max_suff = i;
		}
		k--;
		reverse(all(suff[i]));
		// ans += pref[max_pref];
		while(j <= k)
		{
			if(a[j] != '*')
			{
				yz += a[j];
			}
			j++;
		}
	}
	ans += pref[max_pref];
	ans += yz;
	f(i, 0, n)
	{
		f(j, 0, pref[i].length())
		{
			if(pref[i][j] != pref[max_pref][j])
			{
				return "*";
			}
		}	
	}
	f(i, 0, n)
	{
		int j = suff[max_suff].length() - 1;
		int k = suff[i].length() - 1;
		while(k >= 0 && j >= 0)
		{
			if(suff[i][k--] != suff[max_suff][j--])
				return "*";
		}
	}
	return ans + suff[max_suff];
}
void testCase()
{
	int t = 1;
	cin>>t;
	f(i, 0, t)
	{
		string s = solution(i + 1);
		cout<<"Case #"<<i + 1<<": "<<s<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   
