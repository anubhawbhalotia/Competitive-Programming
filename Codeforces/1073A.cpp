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
	int n;
	S s;
	cin>>n;
	cin>>s;
	int dflag=0;
	f(i,0,n)
	{
		int f[26]={};
		f[s[i]-97]++;
		int cflag=0;
		f(j,i+1,n)
		{
			f[s[j]-97]++;
			int l=j-i+1;
			int flag=0;
			f(k,0,26)
			{
				if(f[k]!=0 && f[k]>floor(l/2.0))
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"YES"<<endl;
				cout<<s.substr(i,j-i+1)<<endl;
				cflag=1;
				break;
			}
		}
		if(cflag==1)
		{
			dflag=1;
			break;
		}
	}
	if(dflag==0)	
		cout<<"NO"<<endl;
}