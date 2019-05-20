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
const int x[] = {-1, 0, 1, 0};
const int y[] = {0, 1, 0, -1};
class Solution {
    int n, m;
    vector <vector <int> > l;
    int dfs(vector<vector<int>>& matrix, int val, int row, int col)
    {
        if(row < 0  || row >= n || col < 0 || col >= m)
            return 0;
        if(val >= matrix[row][col])
            return 0;
        if(l[row][col])
            return l[row][col];
        f(i, 0, 4)
            l[row][col] = max(l[row][col], dfs(matrix, matrix[row][col], row + x[i], col + y[i]));
        l[row][col]++;
        return l[row][col];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0)
            return 0;
        m = matrix[0].size();
        l.resize(n, vector <int>(m));
        int ans = 0;
        f(i, 0, n)
        {
            f(j, 0, m)
                ans = max(ans, dfs(matrix, -1, i, j));
        }
        return ans;
    }
};
