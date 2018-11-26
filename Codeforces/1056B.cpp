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
    ll ex,m;
    vll ml;
    cin>>ex>>m;
    vector < pair <ll,ll> > p;
    fe(i,1,m)
    {
        //cout<<(i*i)%m<<" ";
        ml.pb((i*i)%m);
    }
    //cout<<endl;
    fe(i,1,m)
    {
        fe(j,i,m)
        {
            if((ml[i-1]+ml[j-1])%m==0)
                p.pb(mp(i,j));
        }
    }
    ll cons=ex/m;
    ll f[1001]={};
    fe(i,1,m)
    {
        f[i]+=cons;
    }
    ll x=1;
    fe(i,(m*cons)+1,ex)
    {
        f[x]++;
        x++;
    }
    ll ans;
    f(i,0,p.size())
    {
        //cout<<p[i].fi<<" "<<p[i].se<<endl;
        if(p[i].fi==p[i].se)
            ans+=(f[p[i].fi]*f[p[i].se]);
        else
            ans+=(2*(f[p[i].fi]*f[p[i].se]));
    }
    cout<<ans<<endl;
}
