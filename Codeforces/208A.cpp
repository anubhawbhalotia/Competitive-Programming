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
	string s, a;
	int c;
	cin>>s;
	a = s;
	if(s.length() < 3)
	{
		cout<<s;
		return 0;
	}
	int p = 0;
	string l = "abc";
	f(i,0,s.length())
	{
		a[p] = s[i];
		if(i <= 2)
			l[i] = s[i];
		else
		{
			l[0] = s[i-2];
			l[1] = s[i-1];
			l[2] = s[i];
		}
		if(l == "WUB")
		{
			a[p - 2] = ' ';
			p -= 2;
		}
		p++;
	}
	int i = 0;
	while(a[i] == ' ' && i != a.length())
		a[i++] = 'a';
	i = a.length() - 1;
	while(a[i] == ' ' && i >= 0)
		a[i--] = 'a';
	f(i,0,p)
	{
		if(a[i] != 'a')
		{
			if(a[i] == ' ')
			{
				if(c <1)
				{
					cout<<a[i];
					c++;
				}
			}
			else
			{
				c = 0;
				cout<<a[i];
			}
		}
	}
	cout<<endl;
} 