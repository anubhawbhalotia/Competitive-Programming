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
long dsu[500001];
class disjointSetUnion
{
	long* dsu;
	long n;
public:
	disjointSetUnion(long n)
	{
		dsu = new long[n+1];
		this->n = n;
		f(i, 0, n + 1)
			dsu[i] = i;
	}
	void un(long a, long b)
	{
		dsu[findRoot(a)] = b;
	}
	long get(long index)
	{
		return dsu[index];
	}
	long findRoot(long index)
	{
		vl temp;
		while(dsu[index] != index)
		{
			temp.pb(index);
			index = dsu[index];
		}
		f(i, 0, temp.size())
			dsu[temp[i]] = index;
		return index;
	}
	void show()
	{
		cout<<"DSU[] = ";
		f(i, 0, n + 1)
			cout<<dsu[i]<<" ";
		cout<<endl;
	}
};
int main()
{
	long n, m, k, a;
	cin>>n>>m;
	disjointSetUnion d(m);
	long index[500001] = {};
	f(i, 1, m + 1)
	{
		cin>>k;
		f(j, 0, k)
		{
			cin>>a;
			if(index[a] != 0)
				d.un(index[a], i);
			index[a] = i;
		}
	}
	long f[500001] = {};
	f(i, 1, n + 1)
	{
		index[i] = d.findRoot(index[i]);
		f[index[i]]++;
	}
	// d.show();
	// cout<<"Index[] = ";
	// f(i, 0, n + 1)
	// 	cout<<index[i]<<" ";
	// cout<<endl;
	f[0] = 1;
	f(i, 1, n + 1)
		cout<<f[index[i]]<<" ";
	cout<<endl;
} 