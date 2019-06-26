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
    
    int maxVacationDays(vector<vector<int>>& a, vector<vector<int>>& days) {
        int n = days.size(), k = days[0].size(), temp, g;
        vvi d(k, vi(n, 0));
        vi b(n), c(n);
        f(i, 0, k)
            f(j, 0, n)
                d[i][j] = days[j][i];
        b = d[k - 1];
        fre(i, k - 2, 0)
        {
            f(j, 0, n)
            {
                g = d[i][j];
                temp = 0;
                f(l, 0, n)
                    temp = max(temp, g + ((a[j][l] + (j == l)) * b[l]));
                c[j] = temp;
            }
            b = c;
        }
        int ans = b[0];
        f(i, 1, n)
            ans = max(ans, a[0][i] * b[i]);
        return ans;
    }
};