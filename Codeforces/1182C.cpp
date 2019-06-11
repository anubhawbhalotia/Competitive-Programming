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
template <typename T> T gcd(T a, T b) {return b == 0 ? a : gcd(b, a % b);}   
multiset <pair < pair < int, char>, string>> m, q;
string s[100001];
int nV(int index)
{
	int c = 0;
	char temp;
	f(i, 0, s[index].length())
	{
		temp = s[index][i];
		if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
			c++;
	}
	return c;
}
char lV(int index)
{
	char temp;
	fre(i, s[index].length() - 1, 0)
	{
		temp = s[index][i];
		if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
			return temp;
	}
}
void solution(int t)
{
	int n;
	cin>>n;
	f(i, 0, n)
	{
		cin>>s[i];
		m.insert(mp(mp(nV(i), lV(i)), s[i]));
	}
	auto it = m.begin();
	auto last = it++;
	int c = 1;
	while(it != m.end())
	{
		if(it->fi.fi == last->fi.fi && it->fi.se == last->fi.se)
			c++;
		else 
		{
			if(c % 2 == 1)
			{
				q.insert(*last);
				m.erase(last);
			}
			c = 1;
		}
		last = it++;
	}
	if(c % 2 == 1)
	{
		q.insert(*last);
		m.erase(last);
	}
	if(!q.empty())
	{
		it = q.begin();
		last = it++;
		c = 1;
		while(it != q.end())
		{
			if(it->fi.fi == last->fi.fi)
				c++;
			else 
			{
				if(c % 2 == 1)
					q.erase(last);
				c = 1;
			}
			last = it++;
		}
		if(c % 2 == 1)
			q.erase(last);
	}
	auto a = m.begin();
	auto b = q.begin();
	vector <vector <string> > ans;
	while(a != m.end())
	{
		vector <string> temp;
		if(b == q.end())
		{
			f(i, 0, 4)
			{
				if(a == m.end())
					break;
				temp.pb(a->se);
				a++;
			}
			if(temp.size() < 4)
				break;
		}
		else
		{
			temp.pb(b->se);
			b++;
			temp.pb(b->se);
			b++;
			temp.pb(a->se);
			a++;
			temp.pb(a->se);
			a++;
		}
		ans.pb(temp);
	}
	cout<<ans.size()<<endl;
	f(i, 0, ans.size())
	{
		cout<<ans[i][0]<<" "<<ans[i][2]<<endl;
		cout<<ans[i][1]<<" "<<ans[i][3]<<endl;
	}
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