#include <bits/stdc++.h>
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
class Solution {
public:
	string itoa(ll n)
	{
        int p = 1;
		string s = "";
        if(n < 0)
            p = -1;
        n = abs(n);
		while(n)
		{
			s += (n % 10) + 48;
			n /= 10;
		}
		if(s == "")
			s = "0";
        else
        {
            if(p == -1)
                s += '-';
        }
		reverse(all(s));
		return s;
	}
	string getStr(ll l, ll r)
	{
		if(l == r)
			return itoa(l);
		else
			return itoa(l) + "->" + itoa(r);
	}
    vector<string> findMissingRanges(vector<int>& a, int l, int r) {
        vector <string> ans;
        if(a.empty())
        {
            ans.pb(getStr((ll)l, (ll)r));
            return ans;
        }
    	ll i = 0, last = (ll)l - (ll)1;
    	while(i < a.size())
    	{
    		if((ll)a[i] > last + (ll)1)
    			ans.pb(getStr(last + (ll)1, (ll)a[i] - (ll)1));
    		last = (ll)a[i];
    		i++;
            cout<<last<<endl;
    	}
    	if(r - a[a.size() - 1])
    		ans.pb(getStr((ll)a[a.size() - 1] + (ll)1, (ll)r));
    	return ans;
    }
};