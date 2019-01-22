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
long f[1000000] = {};
int main()
{
	string s;
	cin>>s;
	long i;
	long l=s.length();
	long count=0;
	long c=0,e=1;
	f(i,0,l)
		f[i]=i-1;
	while(c<l-1 && e<l)
	{
		if(s[c]==s[e])
		{
			s[c]='.';
			s[e]='.';
			// cout<<c<<" "<<e<<endl;
			count++;
			e++;
			if(e<l)
				f[e]=f[c];
			else
				break;
			c=f[c];
			

			// for(i=c-1;i>=0;i--)
			// {
			// 	if(s[i]!='.')
			// 		break;
			// }
			if(c==-1)
			{
				c=e;
				e=e+1;
				f[c]=-1;
				if(e<l)
					f[e]=c;
			}
		}
		else
		{
			c=e;
			e++;
		}
	}
	// cout<<count<<endl;
	if(count%2==1)
		cout<<"Yes\n";
	else
		cout<<"No\n";

}