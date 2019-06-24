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
    unordered_set<char> s;
    int atoi(string s)
    {
        int ans = 0;
        f(i, 0, s.length())
            ans = (ans * 10) + (s[i] - 48);
        return ans;
    }
    string itoa(int n)
    {
        string s;
        while(n)
        {
            s += (n%10) + 48;
            n /= 10;
        }
        if(s.length() == 0)
            s = "00";
        if(s.length() == 1)
            s += '0';
        reverse(all(s));
        return s;
    }
    vi& getNextTime(vi &c)
    {
        if(c[1] < 59)
            c[1]++;
        else
        {
            c[1] = 0;
            if(c[0] < 23)
                c[0]++;
            else
                c[0] = 0;
        }
        return c;
    }
    bool isValid(vi &c)
    {
        string t = itoa(c[0]);
        if(s.find(t[0]) == s.end() || s.find(t[1]) == s.end())
            return false;
        t = itoa(c[1]);
        if(s.find(t[0]) == s.end() || s.find(t[1]) == s.end())
            return false;
        return true;
    }
    string nextClosestTime(string t) {
        s.insert(t[0]);
        s.insert(t[1]);
        s.insert(t[3]);
        s.insert(t[4]);
        vi c(2);
        c[0] = atoi(t.substr(0, 2));
        c[1] = atoi(t.substr(3, 2));
        while(1)
        {
            if(isValid(getNextTime(c)))
                return itoa(c[0]) + ':' + itoa(c[1]);
        }
        
    }
};