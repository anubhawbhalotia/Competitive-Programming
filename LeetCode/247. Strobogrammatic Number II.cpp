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
    string s  = "01698";
    string a;
    int z;
    vector <string>  ans;
    void solve(int level)
    {
        if(level == z / 2)
        {
            int temp = level + (z % 2);
            fre(i, temp - (z % 2) - 1, 0)
            {
                if(a[i] == '6')
                    a[temp++] = '9';
                else if(a[i] == '9')
                    a[temp++] = '6';
                else
                    a[temp++] = a[i];
            }
            if(z % 2)
            {
                if(level != 0 || z == 1)
                {
                    a[level] = '0';
                    ans.pb(a);
                }
                a[level] = '1';
                ans.pb(a);
                a[level] = '8';
            }
            ans.pb(a);
            return ;
        }
        f(i, 0, s.size())
        {
            if(level == 0 && i == 0)
                continue;
            a[level] = s[i];
            solve(level + 1);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        z = n;
        f(i, 0, n)
            a += 'a';
        solve(0);
        return ans;
    }
};