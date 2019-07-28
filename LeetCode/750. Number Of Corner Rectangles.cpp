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
    int countCornerRectangles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int p, q, ans = 0, c;
        vvi a(n);
        f(i, 0, n)
        {
            f(j, 0, m)
            {
                if(g[i][j])
                    a[i].pb(j);
            }
        }
        f(i, 0, n)
        {
            f(j, i + 1, n)
            {
                p = 0, q = 0, c = 0;
                while(p != a[i].size() && q != a[j].size())
                {
                    if(a[i][p] == a[j][q])
                    {
                        c++;
                        p++;
                        q++;
                    }
                    else if(a[i][p] > a[j][q])
                        q++;
                    else
                        p++;
                }
                ans += (c * (c - 1)) / 2;
            }
        }
        return ans;
    }
};