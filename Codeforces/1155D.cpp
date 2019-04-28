#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fi first
#define	se second
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
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
void displayArray(ll a[], long end, string arrayName)
{
	cout<<arrayName;
	f(i,1,end)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	long n;
	int x;
	cin>>n>>x;
	long a[n+1];
	ll s[n+1], start[n+1], end[n+1];
	s[0] = 0;
	f(i,1,n+1)
	{
		cin>>a[i];
		s[i] = s[i-1] + (ll)a[i];
	}	
	ll last = 0;
	f(i,1,n+1)
	{
		last += (ll)a[i];
		if(last < 0)
			last = 0;
		end[i] = last;
	}
	last = 0;
	fre(i, n, 1)
	{
		last += (ll)a[i];
		if(last < 0)
			last = 0;
		start[i] = last;
	}
	ll mul[n+1], m = 0;
	mul[0] = 0;
	ll maxMul[n+1];
	maxMul[0] = 0;
	f(i,1,n+1)
	{
		mul[i] = end[i]  - ((ll)x*s[i]);
		if(mul[i] >= mul[m])
			m = i;
		maxMul[i] = m;
	}
	ll maxAns = 0;
	f(i,1,n+1)
	{
		ll ans = ((ll)x * s[i]);
		if(i != n)
			ans += start[i+1];
		ans += mul[maxMul[i]];
		if(ans > maxAns)
			maxAns = ans;
	}
	// displayArray(s, n+1, "s");
	// displayArray(end, n+1, "end");
	// displayArray(start, n+1, "start");
	// displayArray(mul, n+1, "mul");
	// displayArray(maxMul, n+1, "maxMul");
	cout<<maxAns<<endl;
}					