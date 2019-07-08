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
class dsu {
	vi d;
public:
	dsu(int n)
	{
		d.resize(n);
		f(i, 0, n)
			d[i] = i;
	}
	int findRoot(int a)
	{
		stack <int> s;
		while(a != d[a])
		{
			s.push(a);
			a = d[a];
		}
		while(!s.empty())
		{
			d[s.top()] = a;
			s.pop();
		}
		return a;
	}
	void un(int a, int b)
	{
		d[findRoot(a)] = findRoot(b);
	}
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& a, vector<string>& b, 
    	vector<vector<string>>& p) {
    	if(a.size() != b.size())
    		return false;
    	dsu d(p.size() * 2);
    	unordered_map <string, int> m;
    	int x = 0;
        f(i, 0, p.size())
        {
        	if(m.find(p[i][0]) == m.end())
        		m[p[i][0]] = x++;
        	if(m.find(p[i][1]) == m.end())
        		m[p[i][1]] = x++;
        	d.un(m[p[i][0]], m[p[i][1]]);
        }
        f(i, 0, a.size())
        {
        	if(a[i] != b[i])
        	{
        		if(m.find(a[i]) == m.end() || m.find(b[i]) == m.end())
        			return false;
        		if(d.findRoot(m[a[i]]) != d.findRoot(m[b[i]]))
        			return false;
        	}
        }
        return true;
    }
};    