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
#define fr(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef pair<ll,ll> pllll;
int main()
{
	ll n,k,m,a;
	double max=0.0;
	ll suff[100001]={};
	vector <long> v;
	cin>>n>>k>>m;
	f(i,0,n)
	{
		scanf("%lld",&a);
		v.pb(a);
	}
	sort(v.begin(), v.end());
	suff[v.size()-1] = v[v.size()-1];
	fr(i, v.size()-2, 0)
		suff[i] = suff[i+1] + v[i];
	ll ans = suff[0];
	ans += min(k*n, m);
	max= (double)ans/(double)n;
	f(i,0,min(m,n-1))
	{
		ans = suff[i+1];
		ans+=min(k*(n-i-1), m-i-1);
		// cout<<ans<<" "<<n-i-1<<endl;
		if((double)ans/(double)(n-i-1)>max)
			max=(double)ans/(double)(n-i-1);
	}
	cout<<setprecision(7)<<max<<endl;
} 