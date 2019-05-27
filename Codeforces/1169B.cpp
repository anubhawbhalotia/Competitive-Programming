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
    int n, m;
    cin>>n>>m;
    int a[m+1], b[m+1];
    f(i, 0, m)
    	cin>>a[i]>>b[i];
    //for a[0]
    f(k, 0, 2)
    {
    	int f[300001] = {};
    	f[0] = 1;
	    f(i, 1, m)
	    {
	    	if(k == 0)
	    	{
	    		if(a[i] == a[0] || b[i] == a[0])
	    			f[i]++;
	    	}
	    	else
	    	{
	    		if(a[i] == b[0] || b[i] == b[0])
	   				f[i]++;
	   		}
	    }
	    int i = 1;
	    while(i != m)
	    {
	    	if(f[i] == 0)
	    		break;
	    	i++;
	    }
	    if(i == m)
	    {
	    	cout<<"YES"<<endl;
	    	return 0;
	    }
	    int store = i;
	    int x = a[i], y = b[i];
	    while(i != m)
	    {
	    	if(f[i] == 0)
	    	{
	    		if(a[i] == x || b[i] == x)
	    			f[i] = 2;
	    		else
	    			break;
	    	}
	    	i++;
	    }
	    if(i == m)
	    {
	    	cout<<"YES"<<endl;
	    	return 0;
	    }
	    i = store;
	    while(i != m)
	    {
	    	if(f[i] == 0 || f[i] == 2)
	    	{
	    		if(a[i] == y || b[i] == y)
	    			f[i] = 3;
	    		else
	    			break;
	    	}
	   		i++;
	    }
	    if(i == m)
	    {
	    	cout<<"YES"<<endl;
	    	return 0;
	    }
	}
	cout<<"NO"<<endl;
	return 0;
}  