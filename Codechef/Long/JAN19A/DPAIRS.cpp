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
	long n,m,inp;
	set < pll > a,b;
	cin>>n>>m;
	f(i,0,n)
	{
		cin>>inp;
		a.insert(mp(inp,i));
	}
	f(i,0,m)
	{
		cin>>inp;
		b.insert(mp(inp,i));
	}
	// for(set <pll> :: iterator it = a.begin(); it!=a.end(); it++)
	// 	cout<<it->fi<<" "<<it->se<<endl;
	// for(set <pll> :: iterator it = b.begin(); it!=b.end(); it++)
	// 	cout<<it->fi<<" "<<it->se<<endl;

	for(set <pll> :: iterator it = b.begin(); it!=b.end(); it++)
		cout<<a.begin()->second<<" "<<it->second<<endl;
	set < pll > :: iterator  it = a.begin();
	it++; 
	for(;it!=a.end(); it++)
		cout<<it->second<<" "<<b.rbegin()->second<<endl;

}