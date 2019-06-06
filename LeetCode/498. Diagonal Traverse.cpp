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
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    	vi ans;
  		int m = matrix.size(), a, b;
  		if(!m)
  			return 	ans;
  		int n = matrix[0].size();
        ans.resize(m * n);
  		if(!n)
  			return ans;
        int x = 0;
  		fe(i, 0, m + n)
  		{
            a = min(i, m - 1);
            b = max(0, i - (n - 1));
  			if(i % 2 == 0)
            {
  				fre(r, a, b)
                {
  					ans[x++] = (matrix[r][i - r]);
                }
            }
  			else
            {
  				fe(r, b, a)
                {
  					ans[x++] = (matrix[r][i - r]);
                }
            }
  		}
  		return ans;
    }
};
