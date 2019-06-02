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
    string addStrings(string num1, string num2) {
        string ans = "";
        int p = num1.length() - 1, q = num2.length() - 1, c = 0, temp;
        while(p >= 0 && q >= 0)
        {
            temp = num1[p--] - 48 + num2[q--] - 48 + c;
            ans += (char)(temp % 10 + 48);
            c = temp / 10;
        }
        while(p >= 0)
        {
            temp = num1[p--] - 48 + c;
            ans += (char)(temp % 10 + 48);
            c = temp / 10;
        }
        while(q >= 0)
        {
            temp = num2[q--] - 48 + c;
            ans += (char)(temp % 10 + 48);
            c = temp / 10;
        }
        if(c)
            ans += (char)(c + 48);
        reverse(all(ans));
        return ans;
    }
};