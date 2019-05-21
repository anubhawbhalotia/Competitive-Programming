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
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)
            return 0;
        int m = grid[0].size();
        int x[] = {-1, 0, 1, 0};
        int y[] = {0, 1, 0, -1};
        int ans = 0;
        f(i, 0, n)
        {
            f(j, 0, m)
            {
                if(grid[i][j] == 1)
                {
                    int temp = 4;
                    f(k, 0, 4)
                    {
                        int nr = i + x[k];
                        int nc = j + y[k];
                        if(nr >= 0 && nr < n && nc >=0 && nc < m)
                        {
                            if(grid[nr][nc] == 1)
                                temp--;
                        }
                    }
                    ans += temp;
                }
            }
        }
        return ans;
    }
};