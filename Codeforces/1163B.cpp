#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
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
#define fi first
#define se second
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
vi f;
vector <si> s;
si d;
vi a;
int solution(int t)
{
	int n;
	cin>>n;
	a.resize(n);
	f.resize(100001, 0);
	s.resize(100001);
	f(i, 0, n)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	f(i, 1, 100001)
	{
		if(f[i])
		{
			s[f[i]].insert(i);
			d.insert(f[i]);
		}
	}
	fre(i, n - 1, 0)
	{
		if((d.size() == 2 && ((*d.begin() == 1 && s[1].size() == 1) || 
			(*d.rbegin() - *d.begin() == 1 && s[*d.rbegin()].size() == 1))) || 
			(d.size() == 1 && (*d.begin() == 1 || s[*d.begin()].size() == 1)))
				return i + 1;
		s[f[a[i]]].erase(a[i]);
		if(s[f[a[i]]].empty())
			d.erase(f[a[i]]);
		f[a[i]]--;
		if(f[a[i]])
		{
			if(s[f[a[i]]].empty())
				d.insert(f[a[i]]);
			s[f[a[i]]].insert(a[i]);
		}
	}
}
void testCase()
{
	int t = 1;
	// cin>>t;
	f(i, 0, t)
	{
		cout<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}  