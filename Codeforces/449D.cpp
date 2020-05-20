#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<vector<long long>>> vvvl;
typedef vector<pair<int, int>> vpt;
typedef vector<pair<long long, long long>> vptl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
typedef map<int, int> mi;
typedef map<long long, long long> ml;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) x.begin(), x.end()
#define f(i,s,n) for(int i=s;i<n;i++)
#define fe(i,s,n) for(int i=s;i<=n;i++)
#define fr(i,s,n) for(int i=s;i>n;i--)
#define fre(i,s,n) for(int i=s;i>=n;i--)
#define watch1(x) cout <<(#x)<<" = "<<(x)<< endl
#define watch2(x, y) cout<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<endl
#define watch3(x, y, z) cout<<(#x)<<" = "<<(x)<<" "<<(#y)<<" = "<<(y)<<" "<<\
	(#z)<<" = "<<z<<endl
#define log1(x) cout<<x<<endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MOD = 1e9+7;  
int getComplement(int a)
{
	int x = 1, ans = 0;
	f(i, 0, 21)
	{
		if(a % 2 == 0)
		{
			ans += x;
		}
		x *= 2;
		a /= 2;
	}
	return ans;
}
class SumOfSubset
{
private:
	vi sos;
	int n;	//range [0, n)
	int b;	//number of bits
public:
	SumOfSubset(int countBits)	// when range is [0, 1<<n)
	{
		b = countBits;	//number of bits
		n = 1<<b;	//range [0, n)
		sos.resize(n, 0);
	}
	SumOfSubset(int countBits, int rangeEnding)	// when range is [0, n)
	{
		b = countBits;
		n = rangeEnding;
		sos.resize(n, 0);
	}
	vi getSumOfSubsetMemoryOptimised(vi &a)	// better
	{
		f(i, 0, a.size())
		{
			sos[getComplement(a[i])]++;
		}
		f(i, 0, b)
		{
			f(mask, 0, n)
			{
				if(mask & (1<<i))
					sos[mask] += sos[mask ^ (1<<i)];
			}
		}
		return sos;
	}
	vi getSumOfSubsetIterativeVersion(vi &a)	// uses extra memory
	{
		map<pt, int> DP;
		f(mask, 0, n)
		{
			DP[{mask, -1}] = a[mask];
			f(i, 0, b)
			{
				if(mask & (1<<i))
					DP[{mask, i}] = DP[{mask, i - 1}] + 
						DP[{mask ^ (1<<i), i - 1}];
				else
					DP[{mask, i}] = DP[{mask, i - 1}];
			}
			sos[mask] = DP[{mask, b - 1}];
		}
		return sos;
	}
	int getSOSVal(int mask)	// returns sum of subset of mask
	{
		return sos[mask];
	}
};
int modExp(int b, int e)
{
	ll ans = 1;
	while(e)
	{
		int x = 1;
		ll z = b;
		while(x * 2 <= e)
		{
			z = (z * z) % MOD;
			x *= 2;
		}
		e -= x;
		ans = (ans * z) % MOD;
	}
	return ans;
}
int getMod(ll a)
{
	a += MOD;
	return a % MOD;
}
int getCountSetBit(int a)
{
	int c = 0;
	while(a)
	{
		if(a % 2 == 1)
			c++;
		a /= 2;
	}
	return c;
}
int solution(int tc)
{
	int n;
	cin>>n;
	vi a(n);
	f(i, 0, n)
	{
		cin>>a[i];
	}
	sort(all(a));
	SumOfSubset s(22);
	vi b = s.getSumOfSubsetMemoryOptimised(a);
	ll ans = 0;
	ans = getMod(ans);
	// watch1(ans);
	fe(i, 0, 1<<20)
	{
		int c = getComplement(i);
		int g = getCountSetBit(i);
		if(b[c])
		{
			// watch3(i, c, b[c]);
			if(g % 2 == 0)
			{
				ans = ans + modExp(2, b[c]) - 1;
			}
			else
			{
				ans = ans - modExp(2, b[c]) + 1;
			}
			ans = getMod(ans);
		}
	}
	cout<<ans<<endl;
	return 1;
}
void testCase()
{
	int tc = 1;
	// cin>>tc;
	f(i, 0, tc)
	{
		solution(i + 1);
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

