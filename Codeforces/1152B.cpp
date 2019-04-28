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
vl p;
int countNumOfBinaryDigits(long n)
{
	int c = 0;
	while(n)
	{
		c++;
		n = n >> 1;
	}
	return c;
}
int main()
{
	long x;
	cin>>x;
	long l = 1;
	p.pb(1);
	f(i,0,25)
	{
		p.pb(l * 2);
		l = l*2;
	}
	long f = x & (x + 1);
	if(f == 0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	int d;
	vl ans;
	int count = 0;
	while(x)
	{
		d = countNumOfBinaryDigits(x);
		x = x ^ (p[d] - 1);
		d = countNumOfBinaryDigits(x);
		ans.pb(d);
		count++;
		f = x & (x + 1);
		if(f == 0)
			break;
		x++;
		count++;
		f = x & (x + 1);
		if(f == 0)
			break;
	}
	cout<<count<<endl;
	f(i,0,ans.size())
		cout<<ans[i]<<" ";
	cout<<endl;

} 