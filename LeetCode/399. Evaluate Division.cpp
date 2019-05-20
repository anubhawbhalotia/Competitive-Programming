#include<bits/stdc++.h>
using namespace std;
#define fi first
#define	se second
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define beg(x) x.begin()
#define en(x) x.end()
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
const ll INF_ll = 1e18;
const ll INF_l = 1e6 + 1;
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<int,double> pid;
typedef pair<string,int> psi;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
typedef set <pid> spsd;
class Solution {
    spsd v[250];
    int flag;
    double findDen(int x, int b, int f[])
    {
        spsd :: iterator l = v[x].lb(mp(b, -10000));
        if(l != v[x].end())
        {
            if(l->fi == b)
            {
                flag = 1;
                return l->se;
            }
        }
        for(spsd :: iterator it = v[x].begin(); it != v[x].end(); it++)
        {
            if(f[it->fi] == 1)
                continue;
            f[it->fi] = 1;
            double ans = findDen(it->fi, b, f) * it->se;
            if(flag)
                return ans;
        }
        return 1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector <double> ans;
        map <string, int> m;
        int c = 0;
        f(i, 0, equations.size())
        {
            if(m.find(equations[i][0]) == m.end())
                m.insert(psi(equations[i][0], c++));
            if(m.find(equations[i][1]) == m.end())
                m.insert(psi(equations[i][1], c++));
            v[m[equations[i][0]]].insert(mp(m[equations[i][1]], values[i]));
            v[m[equations[i][1]]].insert(mp(m[equations[i][0]], (1.0 /values[i])));
        }
        f(i, 0, queries.size())
        {
            if(m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end())
                ans.pb(-1.0);
            else if(queries[i][0] == queries[i][1])
                ans.pb(1.0);
            else
            {
                int a = m[queries[i][0]], b = m[queries[i][1]];
                int f[250];
                f(j, 0, 250)
                    f[j] = 0;
                flag = 0;
                f[a] = 1;
                double aa = findDen(a, b, f);
                ans.pb(flag ? aa : -1);
            }
        }
        return ans;
    }
};