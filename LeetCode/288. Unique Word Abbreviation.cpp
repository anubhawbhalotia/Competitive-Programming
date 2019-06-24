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
class ValidWordAbbr {
public:
    unordered_map <string, int> m;
    unordered_map <string, string> k;
    unordered_set <string> q;
    string itoa(int n)
    {
        string s;
        while(n)
        {
            s += (n % 10) + 48;
            n /= 10;
        }
        reverse(all(s));
        return s;
    }
    ValidWordAbbr(vector<string>& d) {
        f(i, 0, d.size())
        {
            if(q.find(d[i]) != q.end())
                continue;
            q.insert(d[i]);
            string temp = (d[i].size() >= 2) ? d[i][0] + itoa(d[i].length() - 2) + d[i][d[i].length() - 1] : d[i]; 
            m[temp]++;
            k[temp] = d[i];
        }
    }
    bool isUnique(string word) {
        string temp = (word.size() >= 2) ? word[0] + itoa(word.length() - 2) + word[word.size() - 1] : word;
        if(m.find(temp) == m.end() || (m[temp] == 1 && k[temp] == word))
            return true;
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */