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
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
   	int n, m, a, b, bmin = INT_MAX, ymin = INT_MAX, amax = INT_MIN, xmax = INT_MIN;
   	cin>>n;
   	f(i, 0, n)
   	{
   		cin>>a>>b;
   		bmin = min(bmin, b);
   		amax = max(amax, a);
   	}
   	cin>>m;
   	int x, y;
   	f(i, 0, m)
   	{
   		cin>>x>>y;
   		ymin = min(ymin, y);
   		xmax = max(xmax, x);
   	}
   	if(xmax-bmin > 0 && xmax-bmin >= amax-ymin)
   		cout<<xmax - bmin<<endl;
   	else if(amax-ymin >0 && xmax-bmin <= amax-ymin)
   		cout<<amax-ymin<<endl;
   	else
   		cout<<"0"<<endl;
}  