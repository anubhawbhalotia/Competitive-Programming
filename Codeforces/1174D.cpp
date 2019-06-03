#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
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
#define all(v) beg(v), en(v)
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
void solution(int t)
{
	int n, x, temp;
	cin>>n>>x;
	vi p;
	p.resize(22, 0);
	p[1] = 2;
	f(i, 2, 19)
		p[i] = p[i - 1] * 2;
	vi z;
	unordered_set <int> s;
	int c = 1;
	if(x == 1)
	{
		if(n == 1)
		{
			cout<<"0"<<endl;
			return ;
		}
		c = 2;
	}
	z.pb(c);
	s.insert(c);
	f(i, c + 1, p[n])
	{
		temp = i;
		if(temp == x || (temp ^ z[z.size() - 1]) == p[n] 
			|| s.find(temp ^ x) != s.end())
			continue;
		z.pb(temp);
		s.insert(temp);
	}
	// f(i, 0 ,z.size())
	// 	cout<<z[i]<<" ";
	// cout<<endl;
	cout<<z.size()<<endl;
	cout<<z[0]<<" ";
	f(i, 1, z.size())
	{
		temp = z[i] ^ z[i-1];
		cout<<temp<<" ";
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