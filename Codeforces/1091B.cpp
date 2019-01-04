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
	int n;
	cin>>n;
	long x1[n],x2[n],y1[n],y2[n];
	set < pair < long,long> > sx1,sx2,sy1,sy2;
	f(i,0,n)
	{
		cin>>x1[i]>>y1[i];
		sx1.insert(mp(x1[i],i));
		sy1.insert(mp(y1[i],i));
	}	
	f(i,0,n)
	{
		cin>>x2[i]>>y2[i];
		sx2.insert(mp(x2[i],i));
		sy2.insert(mp(y2[i],i));
	}
	cout<<(sx1.begin())->fi+(sx2.rbegin())->fi<<" "<<(sy1.begin())->fi+(sy2.rbegin())->fi<<endl;


}