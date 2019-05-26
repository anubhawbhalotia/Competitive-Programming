#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long,long> pl;
typedef set<int> si;
typedef set<long> sl;
typedef multiset<int> msi;
typedef multiset<long> msl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(v) beg(v), en(v)
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
const long MOD = 998244353;
class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int x) {
        vi a;
        int t = 0, ns = 0, mx, m = 0;
        f(i, 0, c.size())
        {
            t += c[i];
            a.pb(c[i] * g[i]);
            ns += a[i];
        }
        f(i, 0, x)
            m += a[i];
        // cout<<m<<endl;
        mx = m;
        f(i, x, a.size())
        {
            m += a[i];
            m -= a[i - x];
            mx = max(m, mx);
        }
        // cout<<t<<" "<<ns<<" "<<mx<<endl;
        return t - ns + mx;
    }
};