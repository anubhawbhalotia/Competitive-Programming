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
    int leastInterval(vector<char>& tasks, int n) {
    	vi c(26, 0);
       	f(i, 0, tasks.size())
       	{
       		c[tasks[i] - 65]++;
       	}
       	multiset <int> m;
       	f(i, 0, 26)
       	{
            if(c[i])
       		    m.insert(c[i]);
       	}
       	int ans = 0, y, z;
       	while(!m.empty())
       	{
       		z = 0;
       		y = 0;
       		vector <int> v;
            multiset <int> :: reverse_iterator it = m.rbegin();
            while(z + y != n + 1)
       		{
                if(it != m.rend())
                {
       			    z++;
       				v.pb(*(it++));
                }
                else
                {
                    y = (n + 1) - z;
                }
       		}
			f(i, 0, v.size())
			{
				m.erase(m.lb(v[i]));
				if(v[i] > 1)
					m.insert(v[i] - 1);
			}
       		ans += z + y;
       	}
       	ans -= y;
       	return ans;
    }
};
