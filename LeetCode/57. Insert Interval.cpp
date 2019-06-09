#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& r, vector<int>& nr) {
        int i = 0;
        vector<vector<int>> ans;
        while(i < r.size() && r[i][0] < nr[0])
            ans.pb(r[i++]);
        if(ans.empty())
            ans.pb(nr);
        else
        {
            if(ans[ans.size() - 1][1] >= nr[0])
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], nr[1]);
            else
                ans.pb(nr);
        }
        while(i < r.size())
        {
            if(ans[ans.size() - 1][1] >= r[i][0])
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], r[i++][1]);
            else
                ans.pb(r[i++]);
        }
        return ans;
    }
};