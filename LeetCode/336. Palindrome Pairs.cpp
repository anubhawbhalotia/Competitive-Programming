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
    inline bool isPalindrome(string a)
    {
        fe(i, 0, (a.length() - 1) / 2)
        {
            if(a[i] != a[a.length() - i - 1])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& w) {
        set<pair<char, int>> s;
        vi r, temp;
        f(i, 0, w.size())
        {
            if(w[i] == "")
                r.pb(i);
            else
                s.insert(mp(w[i][w[i].length()-1], i));
        }
        vector <vector <int>> ans;
        set<pair<char, int>> :: iterator it;
        f(i, 0, w.size())
        {
            it = s.lb(mp(w[i][0], 0));
            while(it->fi == w[i][0])
            {
                if(i != it->se)
                {
                    if(isPalindrome(w[i] + w[it->se]))
                    {
                        temp = {i, it->se};
                        ans.pb(temp);
                    }
                }
                it++;
            }
        }
        f(i, 0, w.size())
        {
            if(w[i] != "" && isPalindrome(w[i]))
            {
                f(j, 0, r.size())
                {
                    temp = {i, r[j]};
                    ans.pb(temp);
                    temp = {r[j], i};
                    ans.pb(temp);
                }
            }
        }
        return ans;
    }
};