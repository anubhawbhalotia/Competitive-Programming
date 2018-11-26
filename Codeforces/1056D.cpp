#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
int main()
{
    int n;
    cin>>n;
    int p[n];
    int flag[100001]={};
    if(n==1)
    {
        cout<<"1\n";
        return 0;
    }
    fe(i,2,n)
    {
        cin>>p[i];
        flag[p[i]]=1;
    }
    priority_queue <int> q;
    int ans[100001]={},f[100001]={};
    fe(i,2,n)
    {
        if(!flag[i])
        {
            ans[i]=1;
            q.push(i);
            f[i]=1;
        }
    }
    while(!(q.size()==1 && q.top()==1))
    {
        int temp=q.top();
        q.pop();
        ans[p[temp]]+=ans[temp];
        if(f[p[temp]]==0)
        {
            q.push(p[temp]);
            f[p[temp]]=1;
        }
    }
    sort(ans,ans+n+1);
    f(i,1,n+1)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
