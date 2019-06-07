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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, 
    	int k) {
        vector<vector<int>> ans;
        int a = nums1.size(), b = nums2.size();
        if(!a || !b)
            return ans;
        k = min(a * b, k);
        set <pair <int, pair <int, int> > > s;
        int i = 0, j = 0;
        s.insert(mp(nums1[i] + nums2[j], (mp(i, j))));
        while(k--)
        {	
        	vi temp;
        	i = s.begin()->se.fi;
        	j = s.begin()->se.se;
        	s.erase(s.begin());
        	temp.pb(nums1[i]);
        	temp.pb(nums2[j]);
        	ans.pb(temp);
            if(j < b - 1)
            {
        	    s.insert(mp(nums1[i] + nums2[j + 1], (mp(i, j + 1))));
            }
        	if(i < a - 1)
            {
                s.insert(mp(nums1[i + 1] + nums2[j], (mp(i + 1, j))));
            }
        } 
        return ans;
    }
};