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
    int threeSumSmaller(vector<int>& a, int t) {
    	int n = a.size();
        if(n < 3)
            return 0;
        sort(all(a));
        int i = 0, ans = 0, j, k;
        while(((a[i] <= t && a[i] >= 0) || (a[i] < 0)) && i < n - 2)
        {
        	j = i + 1;
        	k = n - 1;
        	while(((a[j] + a[i] <= t && a[j] >= 0) || (a[j] < 0)) && j < n - 1)
        	{
        		while(a[k] + a[j] + a[i] >= t && k > j + 1)
        			k--;
        		if(a[k] + a[j] + a[i] < t)
        			ans += k - j;
        		j++;
        	}
            i++;
        }
        return ans;
    }
};