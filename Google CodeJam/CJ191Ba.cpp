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
#define all(v) v.begin(),v.end()
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
long lwr_bnd(vl a, long val, long start, long end)
{
	if(val > a[end])
		return end + 1;
	if(val <= a[start])
		return start;
	long mid = (start + end) / 2;
	if(a[mid] < val)
		return lwr_bnd(a, val, mid+1, end);
	else
		return lwr_bnd(a, val, start, mid);
}
long upr_bnd(vl a, long val, long start, long end)
{
	if(val >= a[end])
		return end + 1;
	if(val < a[start])
		return start;
	long mid = (start + end) / 2;
	if(a[mid] <= val)
		return upr_bnd(a, val, mid+1,  end);
	else
		return upr_bnd(a, val, start, mid);
}
int main()
{
	int t;
	cin>>t;
	f(z,1,t+1)
	{
		long np,q;
		cin>>np>>q;
		long x, y, rowMap[1001] = {}, colMap[1001] = {};
		char d;
		sl one, two;
		vl n,s,e,w;
		f(i,0,np)
		{
			cin>>x>>y>>d;
			two.insert(x);	//Column
			one.insert(y);	//Rows
			switch(d)
			{
				case 'N':
					n.pb(y);
					break;
				case 'S':
					s.pb(y);
					break;
				case 'E':
					e.pb(x);
					break;
				case 'W':
					w.pb(x);
			}
		}
		sort(all(n));
		sort(all(s));
		sort(all(e));
		sort(all(w));
		one.insert(0);	//Rows
		two.insert(0);	//Cols
		one.insert(q);
		two.insert(q);
		int p = 0, pp = 0;
		long last = -1;
		for(sl :: iterator it = one.begin(); it !=one.end(); it++)  	//row
		{
			if(*it != last + 1)
				rowMap[p++] = last + 1;
			rowMap[p++] = *it;
			last = *it;
		}
		last = -1;
		for(sl :: iterator it = two.begin(); it !=two.end(); it++)		//col
		{
			if(*it != last + 1)
				colMap[pp++] = last + 1;
			colMap[pp++] = *it;
			last = *it;
		}
		int my = 0, mx = 0, ans, maxAns = 0;
		f(j,0,p)
		{
			ans = 0;
			if(!n.empty())
				ans += lwr_bnd(n, rowMap[j], 0, n.size() - 1);
			if(!s.empty())
		 		ans += s.size() - upr_bnd(s, rowMap[j], 0, s.size() - 1);
		 	if(ans > maxAns)
		 	{
		 		maxAns = ans;
		 		my = j;
		 	}
		}
		maxAns = 0;
		f(j,0,pp)
		{
			ans = 0;
			if(!e.empty())
				ans += lwr_bnd(e, colMap[j], 0,  e.size() - 1);
			if(!w.empty())
				ans += w.size() - upr_bnd(w, colMap[j], 0, w.size() - 1);
			if(ans > maxAns)
			{
				maxAns = ans;
	 			mx = j;
			}
		}
		cout<<"Case #"<<z<<": "<<colMap[mx]<<" "<<rowMap[my]<<endl;
	}	
} 