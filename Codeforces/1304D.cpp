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
typedef struct node
{
	int a;
	struct node* next, *g;
	node(int v)
	{
		a = v;
		next = NULL;
		g = NULL;
	}
}node;
void minLis(int n, string s)
{
	node *c, *l, *p, *temp;
	c = new node(0);
	l = c;
	if(s[0] == '<')
	{
		c->next = new node(0);
		c->g = c->next;
	}
	else
	{
		l = new node(0);
		l->next = c;
		c->g = l;
	}
	p = c->g;
	f(i, 1, s.length())
	{
		if(s[i] == '>')
		{
			temp = l;
			l = new node(0);
			l->next = temp;
			p->g = l;
			p = l;
		}
		else //s[i] == '<'
		{
			if(s[i - 1] == '>')
			{
				temp = c->next;
				c->next = new node(0);
				c->next->next = temp;
				p->g = c->next;
				p = c->next;
			}
			else //s]i - 1] == '<'
			{
				temp = p->next;
				p->next = new node(0);
				p->next->next = temp;
				p->g = p->next;
				p = p->next;
			}
		}
	}
	node *q = l;
	int x = 1;
	while(q != NULL)
	{
		q->a = x++;
		q = q->next;
	}
	q = c;
	while(q != NULL)
	{
		cout<<q->a<<" ";
		q = q->g;
	}
	cout<<endl;
}
void maxLis(int n, string s)
{
	int l = -1, r = 1;
	vi t, b;
	t.pb(0);
	b.pb(0);
	f(i, 0, s.length())
	{
		if(s[i] == '<')
		{
			t.pb(r);
			b.pb(r);
			r++;
		}
		else
		{
			t.pb(l);
			b.pb(l);
			l--;
		}
	}
	sort(all(b));
	int x = 1;
	unordered_map <int, int> m;
	f(i, 0, b.size())
	{
		m[b[i]] = x;
		x++;
	}
	f(i, 0, t.size())
	{
		cout<<m[t[i]]<<" ";
	}
	cout<<endl;
}
void solution(int t)
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	minLis(n, s);
	maxLis(n, s);
}
void testCase()
{
	int t = 1;
	cin>>t;
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