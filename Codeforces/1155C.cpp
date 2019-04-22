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
ll gcd(ll a, ll b)
{
	ll temp;
	while(a)
	{
		temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}
int main()
{
	long n,m;
	cin>>n>>m;
	ll x[n];
	set <pair <ll, long> > d;
	set <pair < ll,long> > :: iterator ht;
	sll v;
	sll :: iterator it;
	cin>>x[0];
	f(i,1,n)
	{
		cin>>x[i];
		v.insert(x[i] - x[i-1]);
	}
	ll inp;
	f(i,0,m)
	{
		cin>>inp;
		d.insert(mp(inp, i));
	}
	it = v.begin();
	ll last = *it;
	it++;
	while(it != v.end())
	{
		last = gcd(last, *it);
		if(last == 1)
			break;
		it++;
	}
	for(ht = d.begin(); ht != d.end(); ht++)
	{
		if((*ht).fi > last)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(last % (*ht).fi == 0)
		{
			cout<<"YES"<<endl;
			cout<<x[0]<<" "<<(*ht).se+1<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
} 