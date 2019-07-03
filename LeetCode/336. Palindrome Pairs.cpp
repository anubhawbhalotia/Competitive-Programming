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
	int checkPalin(vector <string> &w, int &index, int s, int e)
	{
        int x = 0;
		f(i, s, s + (e - s + 1)/2)
		{
			if(w[index][i] != w[index][e - x++])
            {
				return 0;
            }
		}
		return 1;
	}
    vector<vector<int>> palindromePairs(vector<string>& w) {
    	unordered_map <string, int> m;
    	string p;
    	vvi ans;
        f(i, 0, w.size())
        {
        	p = w[i];
        	reverse(all(p));
        	m[p] = i;
        }
        f(i, 0, w.size())
        {
        	f(j, 0, w[i].length())
        	{
        		p = w[i].substr(0, j + 1);
                if(m.find(p) != m.end() && m[p] != i && checkPalin(w, i, j + 1, w[i].length() - 1))
                {
        			ans.pb({i, m[p]});
                }
        		if(j)
        		{
        			p = w[i].substr(j, w[i].length() - j);
	        		if(m.find(p) != m.end() && m[p] != i && checkPalin(w, i, 0, j - 1))
                    {
	        			ans.pb({m[p], i});
                    }
	        	}
        	}
        	if(checkPalin(w, i, 0, w[i].length() - 1) && m.find("") != m.end() && m[""] != i)
        	{
        		ans.pb({i, m[""]});
        		ans.pb({m[""], i});
        	}
        }
        return ans;
    }
};