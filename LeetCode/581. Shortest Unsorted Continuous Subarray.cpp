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
    int findUnsortedSubarray(vector<int>& n) {
    	int left = 0, right = n.size() - 1;
        f(i, 0, n.size())
        {
        	left = i;
        	if(i < n.size() - 1 && n[i] > n[i+1])
        	{
        		break;
        	}
        }
        fre(i, n.size() - 1, 1)
        {
        	right = i;
        	if(i >= 1 && n[i] < n[i-1])
        	{
        		break;
        	}
        }
        int m = INT_MAX, M = INT_MIN;
        fe(i, left, right)
        {
        	m = min(m, n[i]);
        	M = max(M, n[i]);
        }
        while(left > 0 && n[left - 1] > m)
       	{
       		left--;
       	}
       	while(right < n.size() - 1 && n[right + 1] < M)
       	{
       		right++;
       	}
        if(left >= right)
        {
            return 0;
        }
       	return right - left + 1;
    }
};