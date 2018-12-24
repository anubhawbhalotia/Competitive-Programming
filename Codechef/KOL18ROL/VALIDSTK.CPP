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
	int t;
	cin>>t;
	while(t--)
	{
		long  n;
		cin>>n;
		int ans=0;
		long sum=0,a;
		f(i,0,n)
		{
			cin>>a;
			int temp=(a==1)?1:-1;
			sum+=temp;
			if(sum<0)
				ans=1;
		}
		if(ans)
			cout<<"Invalid"<<endl;
		else
			cout<<"Valid"<<endl;

	}
} 