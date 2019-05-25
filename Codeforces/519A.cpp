#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long l;
typedef vector<int> vi;
typedef vector<l> vl;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef set<int> si;
typedef set<l> sl;
typedef multiset<int> msi;
typedef multiset<l> msl;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  
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
#define f(i,s,n) for(l i=s;i<n;i++)
#define fe(i,s,n) for(l i=s;i<=n;i++)
#define fr(i,s,n) for(l i=s;i>n;i--)
#define fre(i,s,n) for(l i=s;i>=n;i--)
const l MOD = 998244353;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	string b = "qrbnpk";    
	string w = "QRBNPK";
	int p[] = {9, 5, 3, 3, 1, 0};
	map <char, int> mb, mw;
	f(i, 0, 6)
	{
		mb[b[i]] = p[i];
		mw[w[i]] = p[i];
	}
	string s;
	int bp = 0, wp = 0;
	f(i, 0, 8)
	{
		cin>>s;
		f(j, 0, 8)
		{
			if(islower(s[j]))
				bp += mb[s[j]];
			else
				wp += mw[s[j]];
		}
	}
	if(bp > wp)
		cout<<"Black"<<endl;
	else if(wp > bp)
		cout<<"White"<<endl;
	else
		cout<<"Draw"<<endl;
}  