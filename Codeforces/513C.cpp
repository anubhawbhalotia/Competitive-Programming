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
typedef long double ld;
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
const int MOD = 998244353;  
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
vi getDigitCount(int a, int n)
{
	vi c(3, 0);
	int z;
	while(a)
	{
		z = a % 3;
		c[z]++;
		a /= 3;
		n--;
	}
	while(n--)
	{
		c[0]++;
	}
	return c;
}
string bitwiseGetDecToBin(int a, int n)
{
	string s = "";
	int z;
	while(a)
	{
		z = a % 3;
		s += (z + 48);
		a /= 3;
		n--;
	}
	while(n--)
	{
		s += '0';
	}
	return s;
}
int solution(int tc)
{
	int n;
	cin>>n;
	vi l(n), r(n);
	int m = INT_MAX, M = INT_MIN;
	f(i, 0, n)
	{
		cin>>l[i]>>r[i];
		m = min(m, l[i]);
		M = max(M, r[i]);
	}
	ld val = 0;
	f(i, m, M + 1)
	{
		int z = modExp(3, n);
		ld ans = 0;
		f(j, 0, z)
		{
			vi c = getDigitCount(j, n);
			string s = bitwiseGetDecToBin(j, n);
			if((c[2] == 1 && c[1] >= 1) || (c[2] == 0 && c[1] > 1))
			{	
				long double b = 1;
				f(k, 0, n)
				{
					if(s[k] == '0')
					{
						b  *=  ((ld)(max(0, (min(i, r[k] + 1) - l[k])) / (ld)(r[k] - l[k] + 1)));
					}	
					else if(s[k] == '1')
					{
						if(i >= l[k] && i <= r[k])
							b *= ((ld)1 / (ld)(r[k] - l[k] + 1));
						else
							b *= 0;
					}
					else
					{
						b *= ((ld)max(0, (r[k] - max(l[k] - 1, i))) / (ld)(r[k] - l[k] + 1));
					}
				}
				ans += b;
			}
		}	
		val += (i * ans);
	}
	cout<<fixed<<setprecision(10)<<val<<endl;
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
