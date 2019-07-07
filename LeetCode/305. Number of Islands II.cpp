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
int x[] = {0, -1, 0, 1}, y[] = {-1, 0, 1, 0}, r, c;
class dsu {
	vector<vector<pii>> d;
public:
	dsu()
	{
		d.resize(r, vector<pii>(c));
		f(i, 0, r)
			f(j, 0, c)
				d[i][j] = mp(i, j);
	}
	pii findRoot(pii a)
	{
		stack <pii> s;
		while(d[a.fi][a.se] != a)
		{
			s.push(a);
			a = d[a.fi][a.se];
		}
		while(!s.empty())
		{
			d[s.top().fi][s.top().se] = a;
			s.pop();
		}
		return a;
	}
	int un(pii a, pii b)
	{
		pii x = findRoot(a);
		pii y = findRoot(b);
		if(x == y)
			return 0;
		d[x.fi][x.se] = y;
		return 1;
	}
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& p) {
    	r = m;
    	c = n;
        dsu h;
    	int ans = 0, tx, ty;
    	vvi a(m, vi(n, 0));
    	vi v;
    	f(i, 0, p.size())
    	{
            if(a[p[i][0]][p[i][1]] == 1)
            {
                v.pb(ans);
                continue;
            }
    		ans++;
    		a[p[i][0]][p[i][1]] = 1;
    		f(j, 0, 4)
    		{
    			tx = p[i][0] + x[j];
    			ty = p[i][1] + y[j];
    			if(tx >= 0 && tx < m && ty >= 0 && ty < n && a[tx][ty] == 1)
    				ans -= h.un({p[i][0], p[i][1]}, {tx, ty});
    		}
    		v.pb(ans);
    	}
        return v;
    }
};