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
	vvi dp;
	void preProcess(string &s, vector <string> &b)
	{
		vector<string> a;
		int i = 0;
		while(i < s.size() - 1)
		{
			if(s[i + 1] == '*')
			{
				a.pb(s.substr(i, 2));
				i += 2;
			}
			else
				a.pb(s.substr(i++, 1));
		}
		if(i == s.length() - 1)
			a.pb(s.substr(i, 1));
		i = 0;
		while(i < a.size() - 1)
		{
			if(a[i].size() == 2 && a[i][0] == a[i + 1][0])
			{
				if(a[i + 1].size() == 1)
					swap(a[i], a[i + 1]);
				else
					a[i] = "";
			}
			i++;
		}
		f(i, 0, a.size())
		{
			if(a[i] != "")
				b.pb(a[i]);
		}
	}
	int solve(string &s, vector <string> p, int x = 0, int y = 0)
	{
		if(dp[x][y] != -1)
			return dp[x][y];
		if(x == s.length() && y == p.size())
			dp[x][y] = 1;
		else if(x < s.length() && y >= p.size())
			dp[x][y] = 0;
		else if(x == s.length())
			dp[x][y] = (p[y].size() == 2) ? solve(s, p, x, y + 1) : 0;
		else if(p[y].length() == 1)
			dp[x][y] = (p[y][0] == s[x] || p[y][0] == '.') ? solve(s, p, x + 1, 
				y + 1) : 0;
		else
			dp[x][y] = (p[y][0] == s[x] || p[y][0] == '.') ? solve(s, p, x + 1, 
				y) | solve(s, p, x, y + 1) : solve(s, p, x, y + 1);
		return dp[x][y];
	}
    bool isMatch(string s, string p) {
    	if(!s.size() && !p.size())
    		return true;
    	if(!p.size())
    		return false;
    	dp.resize(s.length() + 1, vi(p.length() + 1, -1));
        vector<string> a;
    	preProcess(p, a);
        bool m = false;
        f(i, 0, a.size())
        {
            if(a[i].length() == 1)
            {
                m = true;
                break;
            }
        }
        if(!s.size())
            return !m;
    	return solve(s, a);
    }
};
