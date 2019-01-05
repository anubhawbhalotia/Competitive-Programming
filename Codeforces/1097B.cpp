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
int n,a[16];
int flag;
int dp[16][2800]={};
int dpFn(int i, int s)
{
	if(i==n)
	{
		if(s%360 != 0)
			dp[i][s]=2;
		else
			dp[i][s]=1;
		return dp[i][s];
	}
	if(dp[i][s]==0)
	{
		int aa = dpFn(i+1,s+a[i]);
		if(dp[i+1][s+a[i]] == 1)
		{
			dp[i][s]=1;
			return dp[i][s];
		}
		int bb = dpFn(i+1,s-a[i]);
		dp[i][s] = min(aa, bb);
	}
	return dp[i][s];
}
int main()
{
	flag=0;
	cin>>n;
	f(i,0,n)
		cin>>a[i];
	int ans = dpFn(0,0);
	if(ans==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}