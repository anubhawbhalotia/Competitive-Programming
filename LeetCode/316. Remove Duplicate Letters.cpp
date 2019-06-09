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
    string removeDuplicateLetters(string text) {
        stack <char> s;
        vi l;
        l.resize(26, 0);
        f(i, 0, text.length())
        {
            l[text[i] - 97] = i;
        }
        s.push(text[0]);
        set <char> c;
        set <char> :: iterator it;
        c.insert(text[0]);
        f(i, 1, text.length())
        {
            it = c.lb(text[i]);
            if(it == c.end() || *it != text[i])
            {
                while(s.empty() == false && s.top() > text[i] && l[s.top() - 97] >= i)
                {
                    c.erase(s.top());
                    s.pop();
                }
                s.push(text[i]);
                c.insert(text[i]);
            }
        }
        string ans = "";
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(all(ans));
        return ans;
    }
};