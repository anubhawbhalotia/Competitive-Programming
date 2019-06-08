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
    void nextPermutation(vector<int>& nums) {
        int flag = -1;
        fre(i, nums.size()-2, 0)
        {
            if(nums[i] < nums[i+1])
            {
                flag = i;
                f(j, i + 1, (i + 1) + (nums.size() - (i + 1)) / 2)
                    swap(nums[j], nums[nums.size() - (j - i)]);
                break;
            }
        }
        if(flag == -1)
            sort(all(nums));
        else
        {
            f(i, flag + 1, nums.size())
            {
                if(nums[i] > nums[flag])
                {
                    swap(nums[i], nums[flag]);
                    break;
                }
            }
        }           
    }
};