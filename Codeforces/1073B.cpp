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
	long n;
	cin>>n;
	long a[n],b[n],aa[n+1];
	f(i,0,n)
	{
		scanf("%ld",&a[i]);
		aa[a[i]]=i;
	}
	// f(i,0,n+1)
	// 	cout<<aa[i]<<" ";
	// cout<<endl;
	long p=-1;
	f(i,0,n)
	{
		scanf("%ld",&b[i]);
		if(aa[b[i]]<p)
		{
			printf("0 ");
			continue;
		}
		printf("%ld ",aa[b[i]]-p);
		//cout<<aa[b[i]]-p<<" ";
		p=aa[b[i]];
	}
	cout<<endl;

}