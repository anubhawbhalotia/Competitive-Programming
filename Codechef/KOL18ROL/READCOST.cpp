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
#define e 10e+15
ll n,x,m;
ll bs(ll start,ll end,ll val)
{
	// cout<<start<<" "<<end<<endl;
	if(end<=start)
		return start;
	ll mid=(start+end+1)/2;
	if((x+(mid*n))>=val)
		return bs(start,mid-1,val);
	else
		return bs(mid,end,val);

}
int main()
{
	cin>>n>>m>>x;
	ll sum,c;
	while(n!= 0 || x!=0 || m!=0)
	{
		c=x/m;
		sum=0;
		ll ansl=-1,ans;
		do
		{
			// cout<<"bs="<<(c+1)*m<<endl;
			ans=bs(0,e,(c+1)*m);
			if(ans>m-1)
				ans=m-1;
			// cout<<"ans="<<ans<<endl;
			sum=sum+(ans-ansl)*c;
			// cout<<"sum="<<sum<<endl;
			ansl=ans;
			c=(x+((ans+1)*n))/m;
			// cout<<"c="<<c<<endl;
		}while(ansl<m-1);
		cout<<sum<<endl;
		cin>>n>>m>>x;
	}	
}