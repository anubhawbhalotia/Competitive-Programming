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
	long w,h,k;
	cin>>w>>h>>k;
	long ww=w,hh=h,n=1,ans=0,l,r;
	while(k>0)
	{
		l=ww-(4*(n-1));
		r=hh-(4*(n-1));
		if(l==1 || r==1)
			ans+=(l*r);
		else 
			ans+=((ww-(4*(n-1)))*2)+(2*(hh-(4*(n-1))-2));
		k--;
		n++;
	}
	cout<<ans<<endl;
}