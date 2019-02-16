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
	long n,d,s=0,inp,m=1000000000;
	vl v;
	cin>>n;
	f(i,0,n)
	{
		scanf("%ld",&inp);
		v.pb(inp);
		s+=inp;
	}	
	sort(all(v));
	fre(i,n-1,0)
	{
		f(j,2,v[i]-1)
		{
			d=0;
			if(v[i]%j==0)
			{
				d = (v[i] - (v[i]/j))*-1;
				d += (v[0]*j) - v[0];
			}
			if(d<m)
				m=d;
		}
	}
	cout<<s+m<<endl;
} 