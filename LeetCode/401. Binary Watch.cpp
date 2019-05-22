#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
    int cntBin(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += n%2;
            n /= 2;
        }
        return ans;
    }
    string itoa(int a, int flag)
    {
        if(a == 0)
        {
            if(flag)
                return "00";
            else
                return "0";
        }
        string ans = "";
        while(a)
        {
            ans += (char)((a % 10) + 48);
            a /= 10;
        }
        reverse(ans.begin(), ans.end());
        if(ans.length() == 1 && flag == 1)
                ans = '0' + ans;
        return ans;
    }
public:
    vector<string> readBinaryWatch(int n) {
        vector <string> ans;
        int b[60];
        f(i, 0, 60)
            b[i] = cntBin(i);
        f(i, 0, 12)
        {
            if(b[i] <= n)
            {
                f(j, 0, 60)
                { 
                    if(b[j] + b[i] == n)
                        ans.pb(itoa(i, 0) + ":" + itoa(j, 1));
                }
            }
        }
        return ans;
    }
};