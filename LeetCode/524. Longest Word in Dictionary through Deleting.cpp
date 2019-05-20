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
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        f(i, 0, d.size())
        {
            // cout<<d[i]<<endl;
            if(d[i].length() > ans.length() || (d[i].length() == ans.length() && d[i] < ans))
            {
                // cout<<"true"<<endl;
                int k = 0;
                f(j, 0, s.length())
                {
                    if(s[j] == d[i][k])
                    {
                        k++;
                        if(k == d[i].size())
                        {
                            ans = d[i];
                            break;
                        }
                    }
                }
            }
            // cout<<"ans="<<ans<<endl;
        }
        return ans;
    }
};