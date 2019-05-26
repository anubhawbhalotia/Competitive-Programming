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
    vector<int> prevPermOpt1(vector<int>& a) {
        int pl[10001] = {};
        stack <int> s;
        fre(i, a.size() - 1, 0)        
        {
            if(s.empty())
                s.push(i);
            else 
            {
                while(a[s.top()] < a[i])
                {
                    pl[s.top()] = i; 
                    s.pop();
                    if(s.empty())
                        break;
                }
                s.push(i);
            }
        }
        while(!s.empty())
        {
            pl[s.top()] = -1;
            s.pop();
        }
        // f(i, 0, a.size())
        //     cout<<pl[i]<<" ";
        // cout<<endl;
        int l = -1, i = a.size() - 1, y;
        while(i > l)
        {
            if(pl[i] > l)
            {
                l = pl[i];
                y = i;
            }
            i--;
        }
        if(l != -1)
            swap(a[l], a[y]);
        return a;
        
    }
};