#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S string
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
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
ll n,k,A,B;
vector <ll> v;
ll divide(ll start, ll end)
{
	ll si = lb(all(v), start) - v.begin();
	ll ei = ub(all(v), end) - v.begin();
	ll gap = ei - si;
	ll ans = (gap==0)?A:(B*(end-start+1)*gap);
	if(gap ==0 || start==end)
		return ans;
	return min(ans, divide(start, (start+end)/2) + divide((start+end)/2 + 1, end));
}
int main()
{
	cin>>n>>k>>A>>B;
	v.resize(k);
	f(i,0,k)
	{
		scanf("%lld",&v[i]);
		v[i]--;
	}
	sort(all(v));
	cout<<divide(0, (1<<n)-1 )<<endl;
} 	