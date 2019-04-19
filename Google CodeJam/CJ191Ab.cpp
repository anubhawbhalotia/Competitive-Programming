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
long modInverse(long a, long m) 
{ 
    long m0 = m; 
    long y = 0, x = 1; 
 	if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        long q = a / m; 
        long t = m; 
        m = a % m, a = t; 
        t = y;  
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 
int main()
{
	long m, n, t, inp;;
	cin>>t>>n>>m;
	while(t--)
	{
		long f[] = {5,7,9,11,13,16,17}, m[7] = {}, y[7] = {}, rem[7] = {};
		ll M = 1;
		n = 7;
		f(j,0,n)
		{
			M *= f[j];
		    f(l,0,17)
			    cout<<f[j]<<" ";
			cout<<f[j]<<endl;
			long ta = 0;
			f(i,0,18)
			{
				cin>>inp;
				ta+=inp;
			}
			rem[j] = ta;
		}
		f(i,0,n)
		{
			m[i] = M / f[i];
		}
		long ans = 0;
		f(i,0,n)
		{
			y[i] = modInverse(m[i], f[i]);
			ans += y[i]*rem[i]*m[i];
		}
		cout<<ans%M<<endl;
		cin>>inp;
		if(inp==-1)
			return 0;
	}
} 