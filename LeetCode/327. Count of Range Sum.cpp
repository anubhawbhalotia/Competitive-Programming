#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(v) beg(v), en(v)
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
class Solution {
public:
    vl a, temp;
    ll lwr, upr;
    int check(int l, int r, int lim)
    {
        int mid = (l + r) / 2, p = l, q = mid + 1, val = 0;
        while(p <= mid && q <= r)
        {
            if(a[q] - a[p] < lim)
               q++;
            else
            {
                val += q - (mid + 1);
                p++;
            }
        }
        val += ((mid - p + 1) * (q - (mid + 1)));
        return val;
    }   
    void merge(int l, int r)
    {
        int mid = (l + r) / 2, p = l, q = mid + 1, x = 0;
        while(p <= (l + r) / 2 && q <= r)
            temp[x++] = ((a[p] <= a[q]) ? a[p++] : a[q++]);
        while(p <= (l + r) / 2)
            temp[x++] = a[p++];
        while(q <= r)
            temp[x++] = a[q++];
    }
    int ms(int l, int r)
    {
        if(l < r)
        {
            int mid = (l + r) / 2;
            ll t = 0;
            if(l + 1 < r)
            {
                t += ms(l, mid);
                t += ms(mid + 1, r);
            }
            t += check(l, r, upr + 1) - check(l, r, lwr);
            merge(l, r);
            vl :: iterator it = temp.begin();
            fe(i, l, r)
                a[i] = *it++;
            return t;
        }
        return 0;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        temp.resize(nums.size()  + 1);
        a.resize(nums.size()  + 1, 0);
        lwr = lower;
        upr = upper;
        f(i, 0, nums.size())
            a[i + 1] = nums[i] + a[i];
        return ms(0, nums.size());
    }
};