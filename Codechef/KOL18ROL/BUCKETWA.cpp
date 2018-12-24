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
double h,l,r,k,t;
double bs(double start, double end)
{

	double x = (start+end)/2.0;
	if(end-start < 0.0001)
		return x;
	t = (x/(k*sqrt((h*h)+(x*x)))) + (x-r)/(sqrt((r*r)+(x*x)+(l*l)-(2.0*r*x)));
	if(t<0)
		return bs(x+0.0001,end);
	else if(t>0)
		return bs(start,x-0.0001);
	else
		return x;
}
int main()
{
	
	cin>>h>>l>>r>>k;
	while(h!=0 || l!=0 || r!=0 || k!=0)
	{
		double x=bs(0,r);
		//cout<<x<<endl;
		double d=sqrt((h*h)+(x*x)) + sqrt(((r-x)*(r-x))+(l*l));
		cout<<d<<endl;
		cin>>h>>l>>r>>k;
	}

} 