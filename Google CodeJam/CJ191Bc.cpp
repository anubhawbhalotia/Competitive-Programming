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
long n;
class segTree
{
	long* tree;
public:
	segTree()
	{
		tree = new long[n*6];
	}
	long build(long a[], long node, long start, long end)
	{
		if(start == end)
		{
			tree[node] = a[start];
			return tree[node];
		}
		tree[node] = max(build(a, node*2 + 1, start, (start + end) / 2), 
			build(a, node*2 + 2, (start + end) / 2 + 1, end));
		return tree[node];
	}
	long maxQuery(long l, long r, long start, long end, long node = 0)
	{
		if(start > r || end < l)
			return -1;
		if(start >= l && end <= r)
			return tree[node];
		return max(maxQuery(l, r, start, (start + end) / 2,  node*2 + 1),
			maxQuery(l, r, (start + end) / 2 + 1, end ,node*2 + 2));
	}
};
long leftBs(segTree s, long val, long start, long end)
{	
	if(start == end)
	{
		if(s.maxQuery(start, end, 0, n-1) <= val)
			return start;
		else
			return start + 1;
	}
	long mid = (start + end) / 2;
	if(s.maxQuery(mid, end, 0, n - 1) <= val)
		return leftBs(s, val, start, mid);
	else
		return leftBs(s, val, mid+1, end);
}
long rightBs(segTree s, long val, long start, long end)
{
	if(start == end)
	{
		if(s.maxQuery(start, end, 0, n-1) <= val)
			return start;	
		else
			return start - 1;
	}
	long mid = (start + end) / 2 + 1;
	if(s.maxQuery(start, mid, 0, n - 1) <= val)
		return rightBs(s, val, mid, end);
	else
		return rightBs(s, val, start, mid-1);
}
long lBs(segTree s, long val, long start, long end)
{
	if(start == end)
	{
		if(s.maxQuery(start, end, 0, n-1) < val)
			return start;
		else
			return start + 1;
	}
	long mid = (start + end) / 2;
	if(s.maxQuery(mid, end, 0, n - 1) < val)
		return lBs(s, val, start, mid);
	else
		return lBs(s, val, mid + 1, end);
}
long rBs(segTree s, long val, long start, long end)
{
	if(start == end)
	{
		if(s.maxQuery(start, end, 0, n-1) < val)
			return start;
		else
			return start - 1;
	}
	long mid = (start + end) / 2 + 1;
	if(s.maxQuery(start, mid, 0, n - 1) < val)
		return rBs(s, val, mid, end);
	else
		return rBs(s, val, start, mid-1);
}
void nextLargest(long d[], long nl[])
{
	long i = 0;
	stack <long> s;
	while(i <= n - 1)
	{
		while(s.empty() == 0 && d[i] > d[s.top()])
		{
			nl[s.top()] = i;
			s.pop();
		}		
		s.push(i++);
	}
	while(!s.empty())
	{
		nl[s.top()] =  n;
		s.pop();
	}
}	
void prevLargest(long d[], long pl[])
{
	long i = n - 1;
	stack <long> s;
	while(i >= 0)
	{
		while(s.empty() == 0 && d[i] >= d[s.top()])
		{
			pl[s.top()] = i;
			s.pop();
		}
		s.push(i--);
	}
	while(!s.empty())
	{
		pl[s.top()] = -1;
		s.pop();
	}
}
int main()
{
	int t;
	cin>>t;
	long k;
	f(z, 1, t+1)
	{
		cin>>n>>k;
		long c[n], d[n], nl[n], pl[n];
		f(i,0,n)
			cin>>c[i];
		f(i,0,n)
			cin>>d[i];
		segTree s;
		s.build(d, 0, 0, n-1);
		nextLargest(c, nl);
		prevLargest(c, pl);
		long long ans = 0;
		f(i, 0, n)
		{
			long l1 = i - max(pl[i] + 1, leftBs(s, c[i] + k, 0, i)) + 1;
			long r1 = min(nl[i] - 1, rightBs(s, c[i] + k, i, n-1)) - i + 1;
			long l2 = i - max(pl[i] + 1, lBs(s, c[i] - k, 0, i)) + 1;
			long r2 = min(nl[i] - 1, (long)rBs(s, c[i] - k, i, n-1)) - i + 1;
			ans = ans + (l1 * r1) - (l2 * r2);
		}
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
} 
