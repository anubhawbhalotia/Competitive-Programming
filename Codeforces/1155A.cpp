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
	long n;
	string s;
	cin>>n;
	cin>>s;
	set <long> a[30]; 
	f(i,0,n)
		a[s[i]-97].insert(i);
	f(i,0,n-1)
	{
		f(j,0,s[i]-97)
		{
			set <long> :: iterator it = a[j].lb(i);
			if(it!=a[j].end())
			{
				cout<<"YES"<<endl;
				cout<<i+1<<" "<<(*it)+1<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
} 