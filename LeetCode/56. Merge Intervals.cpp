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
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef set<pi> spi;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
typedef multiset<pi> mspi;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        spi s;
        vector<vector<int>> ans;
        int n = intervals.size();
        if(!n)
            return ans;
        int m = intervals[0].size();
        f(i, 0, n)
            s.insert(mp(intervals[i][0], intervals[i][1]));
        spi :: iterator j = s.begin();
        int  start = j->fi, end = j->se;
        j++;
        while(j != s.end())
        {
            if(j->fi > end)
            {
                vector <int> temp;
                temp.pb(start);
                temp.pb(end);
                ans.pb(temp);
                start = j->fi;
                end = j->se;
            }
            else
                end = max(end, j->se);
            j++;
        }
        vector <int> temp;
        temp.pb(start);
        temp.pb(end);
        ans.pb(temp);
        return ans;
    }
};