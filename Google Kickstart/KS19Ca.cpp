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
    int t;
    cin>>t;
    f(z, 1, t + 1)
    {
    	int n, r, s, sr, sc;
    	string p;
    	cin>>n>>r>>s>>sr>>sc;
    	cin>>p;
    	int b[201][201] = {};
    	int cr = 100, cc = 100;
    	b[cr][cc] = 1;
    	f(i, 0, p.length())
    	{
    		switch(p[i])
    		{
    			case 'N':
    				while(b[cr][cc] == 1)
    					cr--;
    				b[cr][cc] = 1;
    				break;
    			case 'S':
    				while(b[cr][cc] == 1)
    					cr++;
    				b[cr][cc] = 1;
    				break;
    			case 'W':
    				while(b[cr][cc] == 1)
    					cc--;
    				b[cr][cc] = 1;
    				break;
    			case 'E':
    				while(b[cr][cc] == 1)
    					cc++;
    				b[cr][cc] = 1;
    		}
    	}
    	cout<<"Case #"<<z<<": "<<cr-100+sr<<" "<<cc-100+sc<<endl;
    }

}  