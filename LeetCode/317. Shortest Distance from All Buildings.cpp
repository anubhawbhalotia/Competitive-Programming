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
    int shortestDistance(vector<vector<int>>& g) {
    	int x[] = {0, -1, 0, 1}, y[] = {-1, 0, 1, 0}, n = g.size(), m = 
            g[0].size(), c, s, last = 0, row, col, tx, ty, ans = INT_MAX;;
    	vvi a = g, b(n, vi(m, 0));
    	f(i, 0, n)
    	{
    		f(j, 0, m)
    		{
	    		if(g[i][j] != 1)
	    			continue;
	    		queue <pii> q;
	    		c = 1;
	    		q.push({i, j});
	    		while(!q.empty())
	    		{
	    			s = q.size();
	    			while(s--)
	    			{
						row = q.front().fi;
						col = q.front().se;
						q.pop();
			    		f(k, 0, 4)
			    		{
			    			tx = row + x[k];
			    			ty = col + y[k];
			    			if(tx >= 0 && tx < n && ty >= 0 && ty < m && 
			    				a[tx][ty] == last)
			    			{
			    				q.push(mp(tx, ty));
			    				a[tx][ty]--;
			    				b[tx][ty] += c;
			    			}

			    		}
			    	}
			    	c++;
		    	}
		    	last--;
	    	}
    	}
    	f(i, 0, n)
    		f(j, 0, m)
    			if(a[i][j] == last)
    				ans = min(ans, b[i][j]);
    	return (ans == INT_MAX) ? -1 : ans;
    }
};