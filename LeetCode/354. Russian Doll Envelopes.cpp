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
	int maxEnvelopes(vector<vector<int>>& e) {
		set<pair<pii, int>> s;
		f(i, 0, e.size())
		{
			s.insert({{e[i][0], e[i][1]}, i});
		}
		vi dp(e.size() + 1, 0);
		auto i = s.begin();
		while(i != s.end())
		{
			if(dp[i->se] != -1)
				continue;
			stack <int> k;
			k.push(i->se);
			int c = 1;
			while(1)
			{
				int t = k.top();
				auto it = s.lb({{e[t][0] + 1, e[t][1] + 1}, 0});
				if(it != s.end())
				{
					if(dp[it->se])
					{
						c = dp[it->se] + 1;
						break;
					}
					else
						k.push(it->se);
				}
				else
					break;
			}
			while(!k.empty())
			{
				dp[k.top()] = c++;
				k.pop();
			}
			ans = max(ans, dp[i-se])
			i++;
		}	
    }
};