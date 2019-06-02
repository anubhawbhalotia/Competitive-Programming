#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector <vector < int> > v;
        v.resize(n + 1);
        vi ans;
        f(i, 0, n)
        {
            v[edges[i][0]].pb(edges[i][1]);
            v[edges[i][1]].pb(edges[i][0]);
        }
        fre(i, n - 1, 0)
        {
            stack <int> s;
            s.push(edges[i][0]);
            vi f;
            f.resize(n+1, 0);
            f[edges[i][0]]++;
            while(!s.empty())
            {
                int temp = s.top();
                s.pop();
                f(j, 0, v[temp].size())
                {
                    if(temp == edges[i][0] && v[temp][j] == edges[i][1])
                        continue;
                    if(!f[v[temp][j]]++)
                    {
                        if(v[temp][j] == edges[i][1])
                            return edges[i];
                        s.push(v[temp][j]);
                    }
                }
            }
        }
        return ans;
    }
};