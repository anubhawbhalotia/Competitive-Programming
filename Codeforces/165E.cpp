#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define x first
#define y second
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
const int MOD = 998244353;
template <typename T,typename U, typename V,typename W>
auto operator+=(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
} 
template <typename T,typename U, typename V,typename W>                            
auto operator+(const pair<T,U> & l, pair<V,W> & r) 
	-> pair<decltype(l.first+r.first),decltype(l.second+r.second)>                
{                                                                                  
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}  
int extendedEuclid(int a, int b, int *x, int *y){if(a == 0){*x = 0;*y = 1;
	return b;}int x1, y1;int gcd = extendedEuclid(b % a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;*y = x1;return gcd;}
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
		sos.resize(n, -1);
	}
	SumOfSubset(int countBits, int rangeEnding)	// when range is [0, n)
	{
		b = countBits;
		n = rangeEnding;
		sos.resize(n, 0);
	}
	vi getSumOfSubsetMemoryOptimised(vi &a)	// better
	{
		f(i, 0, n)
		{
			sos[i] = a[i];
		}
		f(i, 0, b)
		{
			f(mask, 0, n)
			{
				if(mask & (1<<i))
					sos[mask] = max(sos[mask], sos[mask ^ (1<<i)]);
			}
		}
		return sos;
	}
	int getSOSVal(int mask)	// returns sum of subset of mask
	{
		return sos[mask];
	}
};
int getComplement(int x)
{
	int ans = 0;
	f(i, 0, 22)
	{
		int z = x & (1<<i);
		if(z == 0)
		{
			int y = (1<<i);
			ans = ans | y;
		}
	}
	return ans;
}
void solution(int t)
{
	int n, c;
	cin>>n;
	vi a(n), b(1<<22, -1);
	f(i, 0, n)
	{
		cin>>a[i];
		b[a[i]] = a[i];
	}
	SumOfSubset s(22);
	vi sos = s.getSumOfSubsetMemoryOptimised(b);
	f(i, 0, n)
	{
		cout<<sos[getComplement(a[i])]<<" ";
	}
	cout<<endl;
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		solution(i + 1);
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   