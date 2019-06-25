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
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
	int d = 0;
	set <pii> m;
	unordered_map <int, pii> e;
public:
	Solution()
	{
        e.insert(mp(0, mp(-1, 0)));
        e.insert(mp(1, mp(0, -1)));
        e.insert(mp(2, mp(1, 0)));
        e.insert(mp(3, mp(0, 1)));
	}
	void dfs(Robot& b, int r = 0, int c = 0)
	{
		m.insert({r, c});
		f(i, 0, 4)
		{
            auto it = m.lb({r + e[d].fi, c + e[d].se});
			if((it == m.end() || (it->fi != r + e[d].fi || it->se != c + e[d].se)) && b.move())
				dfs(b, r + e[d].fi, c + e[d].se);
			d = (d + 1) % 4;
			b.turnLeft();
		}
		b.clean();
		b.turnLeft();
		b.turnLeft();
		b.move();
		b.turnLeft();
		b.turnLeft();
	}
    void cleanRoom(Robot& robot) {
    	dfs(robot); 
    }
};