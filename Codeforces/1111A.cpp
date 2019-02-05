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
	string a,b;
	long c=0, d=0;
	cin>>a;
	cin>>b;
	if(a.length()!=b.length())
	{
		cout<<"No\n";
		return 0;
	}
	f(i,0,a.length())
	{
		c=0;
		d=0;
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') 
			c++;
		else
			d++;
		if(b[i]=='a' || b[i]=='e' || b[i]=='i' || b[i]=='o' || b[i]=='u')
			c--;
		else
			d--;
		if(c!=0 || d!=0)
			break;
	}	
	if(c!=0 || d!=0)
		cout<<"No\n";
	else 
		cout<<"Yes\n";

}