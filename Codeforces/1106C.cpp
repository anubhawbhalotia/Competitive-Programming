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
	long n;
	long a[300004], f[10005]={};
	cin>>n;
	f(i,0,n)
	{
		scanf("%ld",&a[i]);
		f[a[i]]++;
	}	
	long start=0, end=10001;
	long c=0;
	ll ans=0;
	ll temp, temp1;
	while(c<n)
	{
		while(f[start]==0 && start<end)
			start++;
		while(f[end]==0 && end>start)
			end--;
		// cout<<start<<" "<<end<<endl;
		if(start!=end)
		{
			temp=min(f[start],f[end]);
			temp1 = temp*((((ll)start+(ll)end))*(((ll)start+(ll)end)));
			f[start]-=temp;
			f[end]-=temp;
			
		}
		else
		{
			temp=f[start]/2;
			temp1=temp*((((ll)start+(ll)end))*(((ll)start+(ll)end)));
			f[start]=0;
		}
		ans+=temp1;
		c+=(2*temp);
	}
	cout<<ans<<endl;
}