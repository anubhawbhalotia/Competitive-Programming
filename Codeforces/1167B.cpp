#include<bits/stdc++.h>
using namespace std;
#define fi first
#define	se second
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define beg(x) x.begin()
#define en(x) x.end()
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
const ll INF = 1e18;
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
int main()
{
	int f[600] = {};
	int a[] = {4, 8, 15, 16, 23, 42};
	f(i, 0, 6)
		f[a[i]] = i + 1;
	int c[6][2]  = {}, n;
	f(i, 1, 5)
	{
		cout<<"? "<<i<<" "<<i+1<<endl;
		cin>>n;
		int j = 0;
		while(1)
		{
			if(n % a[j] == 0)
			{
				if(f[(n / a[j])]  != 0)
				{
					// cout<<"j = "<<j<<" f[n / a[j]] = "<<f[(n / a[j])] - 1<<endl;
					c[j][0] += i;
					c[j][1] = j;
					c[f[(n / a[j])] - 1][0] += i;
					c[f[(n / a[j])] - 1][1] = f[n / a[j]] - 1; 
					break;
				}
			}
			j++;
		}
	}
	f(i, 0, 6)
	{
		if(c[i][0] == 4)
			c[i][0] += 5;
		if(c[i][0] == 0)
			c[i][0] += 11;
	}
	f(i,0,6)
	{
		f(j,i+1,6)
		{
			if(c[i][0] > c[j][0])
			{
				swap(c[i][0], c[j][0]);
				swap(c[i][1], c[j][1]);
			}
		}
	}
	cout<<"! ";;
	f(i, 0, 5)
	{
		f[a[c[i][1]]] = 0;
		cout<<a[c[i][1]]<<" ";
	}
	f(i, 0, 6)
	{
		if(f[a[i]] != 0)
			cout<<a[i]<<" ";
	}
	cout<<endl;
} 