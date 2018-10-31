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
	int n;
	ll t;
	cin>>n>>t;
	long inp;
	vl arr;
	f(i,0,n)
	{
		scanf("%ld",&inp);
		arr.pb(inp);
	}
	ll ans=0;
	while(arr.size()!=0)
	{
		//cout<<arr.size()<<endl;
		ll sum=0;
		vl temp;
		f(i,0,arr.size())
		{
			if(arr[i]<=t)
			{
				temp.pb(arr[i]);
				sum+=arr[i];
			}
		}
		arr=temp;
		if(arr.size()==0)
			break;
		ans+=((t/sum)*arr.size());
		t=t%sum;
		f(i,0,arr.size())
		{
			if(arr[i]<=t)
			{
				ans++;
				t-=arr[i];
			}
		}
	}
	cout<<ans<<endl;
}