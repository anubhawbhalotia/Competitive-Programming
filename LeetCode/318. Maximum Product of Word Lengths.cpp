#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(v) beg(v), en(v)
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
const int MOD = 998244353;
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)> {                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)> {                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vi bitRep(words.size());
        int ans = 0;
        f(i, 0, words.size())
        {
            bitRep[i] = 0;
            f(j, 0, words[i].length())
                bitRep[i] |= 1 << (words[i][j] - 'a');
            f(j, 0, i)
            {
                if(!(bitRep[j] & bitRep[i]))
                    ans = max(ans, (int)words[j].length() * 
                        (int)words[i].length());
            }
        }   
        return ans;
    }
};