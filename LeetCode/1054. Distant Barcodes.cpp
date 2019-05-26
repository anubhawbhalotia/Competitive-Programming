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
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int x = 1;
        f(i, 1, b.size())
        {
            if(b[i] == b[i - 1])
            {
                while(b[x] == b[i] && x < b.size() - 1)
                    x++;
                swap(b[x], b[i]);
            }
            else if(x < b.size() - 1)
                x++;
        }
        x = b.size() - 2;
        fre(i, b.size() - 2, 0)
        {
            if(b[i] == b[i + 1])
            {
                while(b[x] == b[i])
                    x--;
                swap(b[x], b[i]);
            }
            else
                x--;
        }
        return b;
    
    }
};