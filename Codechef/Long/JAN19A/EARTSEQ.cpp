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
int p[1000001]={};
vll ans;
vll aa;
ll n;
void sieve(ll x)
{
	for(ll i=2;i<x;i+=2)
		p[i]=1;
	ans.pb(2);
	for(ll i=3;i<x;i+=2)
	{
		if(p[i]==1)
			continue;
		ans.pb(i);
		for(ll j=i+i;j<x;j+=i)
			p[j]=1;
	}
}
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void check()
{
	f(i,0,aa.size())
	{
		long a=gcd(aa[i],aa[(i+1)%n]);
		long b=gcd(a,aa[(i+2)%n]);
		if(a==1 || b!=1)
		{
			cout<<"error"<<" "<<a<<" "<<b<<" "<<aa[i]<<" "<<aa[(i+1)%n]<<" "<<aa[(i+2)%n]<<endl;
			break;
		}
	}
	sll s;
	f(i,0,aa.size())
	{
		if(*(s.lower_bound(aa[i]))==aa[i])
			cout<<"error duplicate "<<aa[i]<<endl;
		s.insert(aa[i]);
	}
}
int main()
{
	sieve(100000);
	// f(i,0,3333)
	// 	cout<<ans[i]<<" ";
	// cout<<endl;
	// cout<<ans.size()<<endl;
	ll t;
	cin>>t;
	while(t--)
	{
		scanf("%lld",&n);
		aa.clear();
		long a=0,bs=1602;
		long b=bs;
		long i=0;
		long z=0;
		while(1)
		{
			// cout<<i<<" "<<ans[a]<<" "<<ans[b];
			printf("%lld ", ans[a]*ans[b]);
			aa.pb(ans[a]*ans[b]);
			i++;
			z++;
			if(i>=n-1)	
				break;
			if(z%2==1)
				a=(a+1)%1602;
			else
				b++;
			if(a==0)
			{
				z=0;
				a=2;
				printf("%lld ", ans[a]*ans[b]);
				aa.pb(ans[a]*ans[b]);
				i++;
				if(i>=n-1)
					break;
				bs+=2;
				if(bs==1604)
					bs=1606;
				b=bs;
			}
		}
		if(z%2==0)
		{
			printf("%lld\n", ans[a]*ans[0]);
			aa.pb(ans[a]*ans[0]);
		}
		else
		{
			printf("%lld\n", ans[b]*ans[0]);
			aa.pb(ans[b]*ans[0]);	
		}
		check();
		// cout<<bs<<endl;

	}	
}