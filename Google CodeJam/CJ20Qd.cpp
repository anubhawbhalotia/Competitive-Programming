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
void complt(vi &a)
{
	f(i, 0, (int)a.size())
	{
		a[i] = 1 - a[i];
	}
}
int solution(int t, int &b)
{
	bool s = 0, d = 0;
	int k, l, x, y;
	vi a(b, 0);
	int z = 0;
	for(int i = 0; i < b / 2; i++)
	{
		if(z % 10 == 0 && i != 0)
		{
			cout<<k + 1<<endl;
			cin>>x;
			cout<<l + 1<<endl;
			cin>>y;
			z += 2;
			if(s == 1 && d == 1)
			{
				
				if(x == a[k])
				{
					if(y != a[l])
					{
						reverse(all(a));
					}
				}
				else
				{
					if(y == a[l])
					{
						reverse(all(a));
					}
					complt(a);
					// if(y == a[l])
					// {
					// 	complt(a);
					// 	reverse(all(a));
					// }
					// else
					// {
					// 	complt(a);
					// }
				}
			}
			else if(s == 1)
			{
				if(x != a[k])
				{
					complt(a);
				}
			}
			else if(d == 1)
			{
				if(y != a[l])
				{
					complt(a);
				}
			}
		}
		cout<<i + 1<<endl;
		cin>>a[i];
		cout<<b - i - 1 + 1<<endl;
		cin>>a[b - i - 1];
		z += 2;
		x = a[i];
		y = a[b - i - 1];
		if(s == 0 && x == y)
		{
			s = 1;
			k = i;
		}
		else if(d == 0 && x != y)
		{
			d = 1;
			l = i;
		}
	}
	f(i, 0, b)
	{
		cout<<a[i];
	}
	cout<<endl;
	char ans;
	cin>>ans;
	return (ans == 'Y') ? 1 : 0;
}
void testCase()
{
	int t = 1, b;
	cin>>t>>b;
	f(i, 0, t)
	{
		int ans = solution(i + 1, b);
		if(!ans)
			exit;
	}
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    testCase();
}   