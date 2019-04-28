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
	int n, inp;
	cin>>n;
	vi a,b,c;
	f(i,0,n)
	{
		cin>>inp;
		if(inp<0)
			a.pb(inp);
		else if(inp>0)
			b.pb(inp);
		else
			c.pb(inp);
	}
	cout<<"1 "<<a[0]<<endl;
	int s = 0;
	if(a.size() % 2 == 0)	
		s = 1;
	cout<<b.size() + a.size() - 1 - s<<" ";
	f(i, 1, a.size() - s)
		cout<<a[i]<<" ";
	f(i,0,b.size())
		cout<<b[i]<<" ";
	cout<<endl;
	cout<<s + c.size()<<" ";
	f(i,a.size()-s, a.size())
		cout<<a[i]<<" ";
	f(i,0,c.size())
		cout<<c[i]<<" ";

} 