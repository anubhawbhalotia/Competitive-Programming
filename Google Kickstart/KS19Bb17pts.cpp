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
int n;
void swap(long l[], int i, int j)
{
	long temp = l[i];
	l[i] = l[j];
	l[j] = temp;
}
long dp(long time, int level, long e[], long l[], long ss, long ans[][105])
{
	if(level>=n)
		return 0;
	if(ans[time][level] == -1)
	{
		long temp1 = dp(time+ss, level+1, e, l, ss, ans) + max((long)0, e[level] - (l[level]*time));
		long temp2 = dp(time, level+1, e, l, ss, ans);
		ans[time][level] = max(temp1, temp2);
	} 
	return ans[time][level];
}
int main()
{
	int t;
	cin>>t;
	f(k,1,t+1)
	{
		cin>>n;
		long s[n], e[n], l[n];
		f(i,0,n)
			cin>>s[i]>>e[i]>>l[i];
		long ans[s[0]*(n+1)][105];
		f(i,0,s[0]*(n+1))
			f(j,0,n+1)
				ans[i][j] = -1;
		fre(i,n-1,1)
		{
			f(j,0,i)
			{
				if(l[i] > l[j])
				{
					swap(l,i,j);
					swap(e,i,j);
				}
			}
		}
		dp(0, 0, e, l, s[0], ans);
		cout<<"Case #"<<k<<": "<<ans[0][0]<<endl;
	}	
} 