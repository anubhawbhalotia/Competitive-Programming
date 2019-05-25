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
	// string s[] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
	string s[] = {"Potter", "Weasly", "Malfoy", "Patil", "Granger", "Riddle", "Diggory"};
	map <string, int> m;
	f(i, 0, 7)
		m[s[i]] = i;
	int l[7][7] = {}, n, p = 3*3*3*3*3*3*3, tans, max2 = 0, temp;
	cin>>n;
	string x, y;
	f(i, 0, n)
	{
		cin>>x>>y;
		l[m[x]][m[y]]++;
	}
	long a, b, c, mx, mn, min1 = 2e9 + 1;
	cin>>a>>b>>c;
	f(i, 1, p)
	{
		temp = i;
		si st;
		vi v;
		long count[3] = {};
		f(j, 0, 7)
		{
			st.insert(temp % 3);
			count[temp % 3]++;
			v.pb(temp % 3);
			temp /= 3;
		}
		if(st.size() < 3)
			continue;
		mx = max(c / count[2], max(a / count[0], b / count[1]));
		mn = min(c / count[2], min(a / count[0], b / count[1]));
		if(mx - mn <= min1)
		{
			// f(i, 0, 7)
			// 	cout<<v[i]<<" ";
			tans = 0;
			f(j, 0, 7)
			{
				f(k, 0, 7)
					if(v[j] == v[k] && l[j][k] == 1)
						tans++;
			}
			if(mx - mn < min1)
				max2 = tans;
			else
				max2 = max(max2, tans);
			min1 = min(min1, mx - mn);
			// cout<<min1<<" "<<max2<<endl;
		}
	}
	cout<<min1<<" "<<max2<<endl;
} 