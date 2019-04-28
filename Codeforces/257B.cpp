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
	long n,m;
	cin>>n>>m;	
	long nn = n,  mm = m;
	string s =  "";
	s += '1';
	n--;
	int turn, c = 0;
	turn = 2;
	c++;
	while(n>0 && m>0)
	{
		if(turn == 2)
		{
			if(s[c-1] == '1')
			{
				s += '0';
				m--;
			}
			else
			{
				s += '1';
				n--;
			}
			turn = 1;
		}
		else
		{
			if(s[c-1] == '1')
			{
				s += '1';
				n--;
			}
			else
			{
				s += '0';
				m--;
			}
			turn = 2;
		}
		c++;
	}
	if(n==0)
		while(m--)
			s += '0';
	if(m==0)
		while(n--)
			 s += '1';
	char last = s[0];
	int v = 0, p = 0;
	f(i,1,s.length())
	{
		if(s[i] == last)
			p++;
		else
			v++;
		last = s[i];
	}

	n = nn, m = mm;
	s =  "";
	s += '0';
	m--;
	turn, c = 0;
	turn = 2;
	c++;
	while(n>0 && m>0)
	{
		if(turn == 2)
		{
			if(s[c-1] == '1')
			{
				s += '0';
				m--;
			}
			else
			{
				s += '1';
				n--;
			}
			turn = 1;
		}
		else
		{
			if(s[c-1] == '1')
			{
				s += '1';
				n--;
			}
			else
			{
				s += '0';
				m--;
			}
			turn = 2;
		}
		c++;
	}
	if(n==0)
		while(m--)
			s += '0';
	if(m==0)
		while(n--)
			 s += '1';
	last = s[0];
	int vv = 0, pp = 0;
	f(i,1,s.length())
	{
		if(s[i] == last)
			pp++;
		else
			vv++;
		last = s[i];
	}
	if(p > pp)
		cout<<p<<" "<<v<<endl;
	else
		cout<<pp<<" "<<vv<<endl;

} 