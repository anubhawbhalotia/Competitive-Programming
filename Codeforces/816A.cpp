#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef pair<int,int> pi;
typedef pair<long,long> pl;
typedef set<int> si;
typedef set<long> sl;
typedef multiset<int> msi;
typedef multiset<long> msl;
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
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
const long MOD = 998244353;
string itoa(int i)
{
	if(i == 0)
		return "00";
	int nd = 0;
	string a = "";
	while(i)
	{
		a += (char)((i % 10) + 48);
		i/=10;
		nd++;
	}
	if(nd == 1)
		a += '0';
	reverse(all(a));
	return a;
}
bool isPalin(string a)
{
	f(i, 0, a.length() / 2)
	{
		if(a[i] != a[a.length() - i - 1])
			return false;
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    string s;
    int c = 0, hr, mint;
   	cin>>s;
   	hr = (s[0]-48)*10 + (s[1]-48);
   	mint = (s[3]-48)*10 + (s[4]-48);
   	while(1)
   	{
   		if(isPalin(itoa(hr) + itoa(mint)))
   		{
   			cout<<c<<endl;
   			break;
   		}
   		mint++;
   		c++;
   		if(mint == 60)
   		{
   			hr++;
   			mint = 0;
   			if(hr == 24)
   				hr = 0;
   		}
   	} 
}  