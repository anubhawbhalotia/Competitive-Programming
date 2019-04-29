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
	int t;
	cin>>t;
	f(z,1,t+1)
	{
		long np,q;
		cin>>np>>q;
		long x[np], y[np];
		char d[np];
		long ans[1001][1001] = {};
		long my = 0, mx = 0;
		set <long> one,  two;
		long rowMap[1001] = {}, rowUnmap[100001] = {};
		long colMap[1001] = {}, colUnmap[100001] = {};
		f(i,0,np)
		{
			cin>>x[i]>>y[i]>>d[i];
			two.insert(x[i]);
			one.insert(y[i]);
		}
		one.insert(0);
		two.insert(0);
		one.insert(q);
		two.insert(q);
		int p = 0;
		long last;
		for(set < long > :: iterator it = one.begin();
		 it !=one.end(); it++)  	//row
		{
			if(it == one.begin())
			{
				last = *it;
				rowMap[0] = *it;
				rowUnmap[*it] = 0;
				p++;
			}
			else
			{
				if(*it == last)
					continue;
				if(*it == last + 1)
				{
					rowMap[p] = *it;
					rowUnmap[*it] = p;
					last = *it;
					p++;
				}
				else
				{
					rowMap[p] = last + 1;
					rowUnmap[last + 1] = p;
					p++;
					rowMap[p] = *it;
					rowUnmap[*it] = p;
					last = *it;
					p++;
 				}
			}
		}
		int pp = 0;
		for(set < long > :: iterator it = two.begin();
		 it !=two.end(); it++)		//col
		{
			if(it == two.begin())
			{
				last = *it;
				colMap[0] = *it;
				colUnmap[*it] = 0;
				pp++;
			}
			else
			{
				if(*it == last)
					continue;
				if(*it == last + 1)
				{
					colMap[pp] = *it;
					colUnmap[*it] = pp;
					last = *it;
					pp++;
				}
				else
				{
					colMap[pp] = last + 1;
					colUnmap[last + 1] = pp;
					pp++;
					colMap[pp] = *it;
					colUnmap[*it] = pp;
					last = *it;
					pp++;
 				}
			}
		}
		f(j,0,p) //x
		{
			f(i,0,pp) //y
			{
				f(k,0,np)
				{
					// cout<<d[k]<<endl;
					switch(d[k])
					{
						case 'N':
							if(j > rowUnmap[y[k]])
								ans[j][i]++;
							break;
						case 'S':
							if(j < rowUnmap[y[k]])
								ans[j][i]++;
							break;
						case 'E':
							if(i > colUnmap[x[k]])
								ans[j][i]++;
							break;
						case 'W':
							if(i < colUnmap[x[k]])
								ans[j][i]++;
							break;
					}
				}
				if(ans[j][i] > ans[my][mx])
				{
					mx = i;
					my = j;
				}
			}

		}
		cout<<"Case #"<<z<<": "<<colMap[mx]<<" "<<rowMap[my]<<endl;
	}	
} 