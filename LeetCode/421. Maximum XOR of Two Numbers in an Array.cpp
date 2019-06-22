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
	int solve(vi &a, vi &b, int index)
	{
       if(index == 0 || (a.size() == 0 && b.size() == 0))
			return 0;
		int x = 1 << (index - 1);
		vi c, d, e, f;
		f(i, 0, a.size())
		{
			if((a[i] & x))
				d.pb(a[i]);
			else
				c.pb(a[i]);
		}
		f(i, 0, b.size())
		{
			if((b[i] & x))
				f.pb(b[i]);
			else
				e.pb(b[i]);
		}
		int ans = INT_MIN;
        if(c.size() && f.size())
			ans = x + solve(c, f, index - 1);
		if(d.size() && e.size())
			ans = max(ans, x + solve(d, e, index - 1));
        if(ans == INT_MIN)
        {
		    if(c.size() && d.size())
			    ans = max(ans, x + solve(c, d, index - 1));
		    else if(e.size() && f.size())
			    ans = max(ans, x + solve(e, f, index - 1));
		    else
			    ans = max(ans, solve(a, b, index - 1));
        }
		return ans;
	}
    int findMaximumXOR(vector<int>& nums) {
        vi temp;
        int index = 0, m = INT_MIN;
        f(i, 0, nums.size())
            m = max(m, nums[i]);
        while(m)
        {
            index++;
            m = m >> 1;
        }
    	return solve(nums, temp, index);
    }
};
