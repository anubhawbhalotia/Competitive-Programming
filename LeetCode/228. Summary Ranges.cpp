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
    string itoa(long a)
    {
        if(a == 0)
            return "0";
        string temp = "";
        long n = 0;
        if(a < 0)
        {
            n = 1;
            a = a * -1;
        }
        while(a)
        {
            temp += char((a % 10) + 48);
            a /= 10;
        }
        if(n)
            temp += '-';
        reverse(temp.begin(), temp.end());
        // cout<<temp<<endl;
        return temp;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string temp = "";
        vector <string> ans;
        if(nums.size() == 0)
            return ans;
        int p = nums[0];
        temp += itoa((long)p);
        
        int c = 0;
        f(i, 1, nums.size())
        {
            if(nums[i] == p + 1)
            {
                c++;
                p = nums[i];
            }
            else
            {
                if(c)
                {
                    temp += "->" + itoa((long)p);
                    c = 0;
                }
                ans.pb(temp);
                p = nums[i];
                temp = itoa((long)p);
            }
        }
        if(c)
            temp += "->" + itoa((long)p);
        ans.pb(temp);
        return ans;
        
    }
};