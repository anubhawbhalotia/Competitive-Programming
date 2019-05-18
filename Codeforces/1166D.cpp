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
	int q;
	cin>>q;
	ll p[60];
	p[0] = 1;
	fe(i,1,51)
		p[i] = p[i-1] << 1;
	while(q--)
	{
		ll a, b, m;
		cin>>a>>b>>m;
		if(a == b)
		{
			cout<<"1 "<<a<<endl;
			continue;
		}
		int n = 1;
		vector <ll> v;
		v.pb(0);
		ll val = a;
		while(val <= b)
		{
			v.pb(val);
			if(n++ == 1)
				val += 1;
			else
				val *= 2;
		}
		n--;
		ll temp = p[n-2];
		int x = -1, y = -1;
		while(temp)
		{
			x++;
			temp /= 10;
		}
		temp = a + m;
		while(temp)
		{
			y++;
			temp /= 10;
		}
		if(x + y <= 17)		
		{	
			if(p[n - 2] * (a + m) < b)
			{
				cout<<"-1"<<endl;
				continue;
			}
		}
		ll d = b - v[n];
		ll k = d / p[n - 2];
		d -= k * p[n - 2];
		if(k != 0)
		{
			val = p[n - 2] - 1;
			fre(i, n, 2)
			{
				v[i] += (k * val) + k;
				val = val >> 1;
			}
		}
		int flag = 0;
		if(d)
		{
			fre(i, n, 2)
			{
				if(flag)
					v[i] += 1;
				v[i] += d;
				flag = d % 2;
				if(d == 0)
					break;
				d = d >> 1;
			}
		}
		cout<<n<<" "; 
		f(i, 1, n + 1)
			cout<<v[i]<<" ";
		cout<<endl;
	}	
} 