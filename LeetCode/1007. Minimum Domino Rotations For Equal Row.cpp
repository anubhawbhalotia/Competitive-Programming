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
    int minDominoRotations(vector<int>& a, vector<int>& b) {
    	int ans = INT_MAX, x = -1;
        while(x++ < 2)
        {
        	int flag = 0, c = 0, d = 0;
            int i = (x == 0) ? a[0] : b[0];
        	f(j, 0, a.size())
        	{
	        	if(a[j] != i && b[j] != i)
	        	{
	        		flag = 1;
	        		break;
	        	}
	        	if(a[j] != i)
	        		c++;
	        	if(b[j] != i)
	        		d++;
	        }
	        if(!flag)
	        {
	        	ans = min(ans, c);
	        	ans = min(ans, d);
	        }
        }	
        return (ans == INT_MAX) ? -1 : ans;
    }
};
