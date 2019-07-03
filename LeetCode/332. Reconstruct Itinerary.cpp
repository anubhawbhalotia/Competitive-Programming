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
	vector <bool> flag;
	vector <set<pair<string, int>>> edge;
	vector <string> ans;
	int n;
    unordered_map <string, int> m;
	int traverse(string node, int c)
	{
		if(c == n + 1)
			return 1;
        auto it = edge[m[node]].begin();
		while(it != edge[m[node]].end())
		{
			if(flag[it->se] == true)
			{
				it++;
				continue;
			}
			flag[it->se] = true;
			if(traverse(it->fi, c + 1))
			{
				ans[c] = (it++)->fi;
				return 1;
			}
			else
			{
				flag[(it++)->se] = false;
			}
		}
		return 0;
	}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    	n = tickets.size();
        flag.resize(n, false);
    	ans.resize(n + 1);
        edge.resize(n);
        int x = 0;
	    f(i, 0, n)
	    {	
	    	if(m.find(tickets[i][0]) == m.end())
	    		m[tickets[i][0]] = x++;
	    	if(m.find(tickets[i][1]) == m.end())
	    		m[tickets[i][1]] = x++;
	    	edge[m[tickets[i][0]]].insert({tickets[i][1], i});
	    }
	    ans[0] = "JFK";
	    traverse("JFK", 1);
	    return ans;
    }
};