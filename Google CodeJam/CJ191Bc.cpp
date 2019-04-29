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
int main()
{
	int t;
	cin>>t;
	long n,k;
	f(z, 1, t+1)
	{
		cin>>n>>k;
		long c[n], d[n];
		f(i,0,n)
			cin>>c[i];
		f(i,0,n)
			cin>>d[i];
		long ans = 0;
		f(i,0,n)
		{
			f(j,i,n)
			{
				long mc = 0,  md = 0;
				fe(h,i,j)
				{
					if(c[h] > mc)
						mc = c[h];
					if(d[h] > md)
						md = d[h];
				}
				// cout<<i<<" "<<j<<" "<<abs(mc-md)<<endl;
				if(abs(mc-md) <= k)
					ans++;
			}
		}
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
} 