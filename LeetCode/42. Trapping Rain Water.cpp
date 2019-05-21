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
public:
    int trap(vector<int>& h) {
        if(h.size() == 0)
            return 0;
        int mh = 0, minMh, maxMh;
        f(i, 0, h.size())
        {
            if(h[i] > h[mh] || i == 0)
            {
                mh = i;
                minMh = mh;
                maxMh = mh;
            }
            else if(h[i] == h[mh])
                maxMh = mh;
        }
        int i = 0, maxSoFar = -1, ans = 0;
        while(i != minMh)
        {
            if(h[i] > maxSoFar)
                maxSoFar = h[i];
            else
                ans += maxSoFar - h[i];
            i++;
        }
        while(i != maxMh)
        {
            ans += h[maxMh] - h[i];
            i++;
        }
        i = h.size() - 1;
        maxSoFar = -1;
        while(i != maxMh)
        {
            if(h[i] > maxSoFar)
                maxSoFar = h[i];
            else
                ans += maxSoFar - h[i];
            i--;
        }
        return ans;
    }
};