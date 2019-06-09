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
    ll num, den;
    string itoa(ll n)
    {
        string ans = "";
        while(n)
        {
            ans += (n%10) + 48;
            n /= 10;
        }
        reverse(all(ans));
        return ans;
    }
    ll check(string s)
    {
        fe(i, 1, s.size() / 2)
        {
            if(s.substr(s.length() - i, i) == s.substr(s.length() - 2*i, i))
                return i;
        }
        return 0;
    }
    string fractionToDecimal(int numerator, int denominator) {
        string l, r = "";
        num = numerator;
        den = denominator;
        if((num < 0 && den > 0) || (num > 0 && den < 0))
        {
            l = "-";    
        }
        num = abs(num);
        den = abs(den);
        if(num >= den)
        {
            l += itoa(num / den);
            num = num % den;
        }
        else
            l+='0';
        set <pair<int, int>> s;
        set <pair<int, int>> :: iterator it;
        int rep = -1;
        while(num)
        {
            if(!s.empty())
            {
                it = s.lb(mp(num, -1));
                if(it != s.end() && it->fi == num)
                {
                    rep = it->se;
                    break;
                }
                else
                    s.insert(mp(num, r.size()));    
            }
            else
                s.insert(mp(num, r.size()));
            num *= 10;
            while(num < den)
            {
                r += '0';
                s.insert(mp(num, r.size()));
                num *= 10;
            }
            r += itoa(num / den);
            num = num % den;
        }
        if(rep+1)
        {
            l = l + '.' + r.substr(0, rep) + '(' + r.substr(rep, r.length() - rep) + ')';
            return l;
        }
        if(r == "")
            return l;
        return l + '.' + r;
    }
};