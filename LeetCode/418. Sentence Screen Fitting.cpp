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
    int wordsTyping(vector<string>& s, int rows, int cols) {
        int c = 0, ans = 0, i = 0, j, fw, st, en, mid;
        vi p(s.size() + 1, 0);
        f(i, 0, s.size())
            p[i + 1] = p[i] + s[i].size() + 1;
        while(i < rows)
        {
            j = 0;
            while(j < cols)
            {
                fw = (cols - j) / p[s.size()];
                if(fw)
                {
                    j += (p[s.size()]*fw);
                    ans += fw;
                }
                if(cols - j == p[s.size()] - 1)
                {
                    ans++;
                    j += p[s.size()] - 1;
                }
                if(cols - j >= s[c].length())
                {
                    st = c + 1, en = s.size();
                    while(st < en)
                    {
                        mid = (st + en) / 2 + 1;
                        if(p[mid] - p[c] - 1 <= cols - j)
                            st = mid;
                        else
                            en = mid - 1;
                    }
                    j += p[st] - p[c];
                    c = st % s.size();
                    if(!c)
                        ans++;
                }
                else
                    break;
            }
            i++;
        }
        return ans;
    }
};