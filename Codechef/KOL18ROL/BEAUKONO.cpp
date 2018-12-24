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
	long a,n,sum;
	int col[200010];
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}
		cin>>a;
		int r[200010]={};
		long x[2]={};
		r[1]=1;
		r[2]=1;
		col[1]=0;
		col[2]=1;
		x[0]=1;
		x[1]=1;
		sum=1;	
		f(i,1,n)
		{
			cin>>a;
			col[i+2]=1-col[a];
			if(r[a]==1)
			{
				x[col[i+2]]--;
				r[a]=0;
			}
			r[i+2]=1;
			x[col[a]]++;
			//cout<<x[0]<<" "<<x[1]<<endl;
			sum+=max(x[0],x[1]);
		}
		cout<<sum<<endl;

	}	
} 