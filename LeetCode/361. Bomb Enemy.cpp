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
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(!grid.size())
            return 0;
        if(!grid[0].size())
            return 0;
        vvi a(grid.size(), vi(grid[0].size(), 0));
        int ans = 0, c;
        f(i, 0, grid.size())
        {
            c = 0;
            f(j, 0, grid[0].size())
            {
                if(grid[i][j] == 'E')
                    c++;
                else if(grid[i][j] == 'W')
                    c = 0;
                else
                    a[i][j] += c;
            }
        }
        f(i, 0, grid.size())
        {
            c = 0;
            fre(j, grid[0].size() - 1, 0)
            {
                if(grid[i][j] == 'E')
                    c++;
                else if(grid[i][j] == 'W')
                    c = 0;
                else
                    a[i][j] += c;
            }
        }
        f(j, 0, grid[0].size())
        {
            c = 0;
            f(i, 0, grid.size())
            {
                if(grid[i][j] == 'E')
                    c++;
                else if(grid[i][j] == 'W')
                    c = 0;
                else
                    a[i][j] += c;
            }
        }
        f(j, 0, grid[0].size())
        {
            c = 0;
            fre(i, grid.size() - 1, 0)
            {
                if(grid[i][j] == 'E')
                    c++;
                else if(grid[i][j] == 'W')
                    c = 0;
                else
                {
                    a[i][j] += c;
                    ans = max(ans, a[i][j]);
                }
            }
        }
        return ans;
    }
};