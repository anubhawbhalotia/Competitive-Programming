#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
const int MOD = 998244353;
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}     
class Solution {
public:
    int kEmptySlots(vector<int>& bulb, int k) {
        if(bulb.size() < k + 2)
            return -1;
        vi b(bulb.size());
        f(i, 0, bulb.size())
            b[bulb[i] - 1] = i + 1;
        f(i, 0, b.size())
            cout<<b[i]<<" ";
        cout<<endl;
        deque <int> q;
        f(i, 1, k + 1)
        {
            while(!q.empty() && q.back() > b[i])
                q.pop_back();
            q.push_back(b[i]);
        }
        int ans = INT_MAX;
        int i = k + 1;
        while(i < b.size())
        {
            if(k == 0 || q.front() > b[i - k - 1] && q.front() > b[i])
                ans = min(ans,max(b[i - k - 1], b[i]));
            if(q.front() == b[i - k])
                q.pop_front();
            while(!q.empty() && q.back() > b[i])
                q.pop_back();
            q.push_back(b[i]);
            i++;
        }
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};