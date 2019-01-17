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
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ll n,t,x,y,z,T,p,q,g;
	cin>>T;
	while(T--)
	{
		scanf("%lld %lld %lld %lld %lld",&n,&t,&x,&y,&z);
		q=(2*n)+1;
		switch(t)
		{
			case 1:
				if(x==z)
					p=x;
				else
					p=(2*n)+1-z;
				break;
			case 2:
				if(x==z)
					p=0;
				else
				 	p=(2*n)+1-(2*y);
				break;
			case 3:
				if(x==z)
					p=x;
				else
					p=(2*n)+1-x;
				break;
			case 4:
				if(x==z)
					p=0;
				else
					p=(2*n)+1-(2*y);
		}
		g=gcd(p,q);
		p/=g;
		q/=g;
		printf("%lld %lld\n",p,q);
	}

}