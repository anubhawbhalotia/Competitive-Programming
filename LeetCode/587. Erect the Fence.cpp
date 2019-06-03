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
    unordered_set <int> s; 
	inline int orientation(vi p, vi q, vi r)
	{
		return ((q[0] - p[0]) * (r[1] - q[1])) - ((q[1] - p[1]) * (r[0] - 
			q[0]));		
	}
	int findLeftmostPoint(vvi p)
	{
		int m = 0;
		f(i, 0, p.size())
		{
            s.insert(i);
			if(p[i][0] < p[m][0])
				m = i;
		}
		return m;
	}
	inline int euclDist(vi p, vi q)
	{
		return ((p[1] - q[1]) * (p[1] - q[1])) + ((p[0] - q[0]) * (p[0] - q[0]));
	}
    vvi outerTrees(vvi& pts) 
    {
        if(pts.size() <= 2)
            return pts;
    	int p = findLeftmostPoint(pts);
    	int start = p;
    	vvi ans;	
        s.erase(p);
        int q = *s.begin();
        vi f;
        f.resize(pts.size(), 0);
        int x = 1;
    	do
    	{
            ans.pb(pts[p]);
    		f[p]++;
    		f[q]++;
    		f(i, 0, pts.size())
    		{
    			if(f[i] == x)
    				continue;
    			f[i]++;
    			int orient = orientation(pts[p], pts[q], pts[i]);
    			if(orient < 0 || (orient == 0 && euclDist(pts[p], pts[i]) < euclDist(pts[p], pts[q]) 
                && s.find(i) != s.end()))
    				q = i;
    		}
    		p = q;
            s.erase(p);
            int flag = 0;
            if(s.empty())
            {
                ans.pb(pts[p]);
                return ans;
            }
            q = *s.begin();
            x++;
    	}while(p != start);
    	return ans;
    }
};