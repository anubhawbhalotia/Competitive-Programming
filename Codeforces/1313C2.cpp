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
int n;
vi m, ns, ps;
vi nxt_sma()
{
	stack <int> s;
	vi ans(n);
	f(i, 0, n)
	{
		if(!s.empty())
		{
			while(m[s.top()] > m[i])
			{
				ans[s.top()] = i;
				s.pop();
				if(s.empty())
					break;
			}
		}
		s.push(i);
	}
	while(!s.empty())
	{
		ans[s.top()] = -1;
		s.pop();
	}
	return ans;
}
vi prev_sma()
{
	stack <int> s;
	vi ans(n);
	fre(i, n-1, 0)
	{
		if(!s.empty())
		{
			while(m[s.top()] > m[i])
			{
				ans[s.top()] = i;
				s.pop();
				if(s.empty())
					break;
			}
		}
		s.push(i);
	}
	while(!s.empty())
	{
		ans[s.top()] = -1;
		s.pop();
	}
	return ans;
}
vl solv_ns()
{
	vl ans(n);
	fre(i, n-1, 0)
	{
		ans[i] = m[i];
		if(ns[i] != -1)
		{
			ans[i] += ans[ns[i]];
			ans[i] += (ll)((ns[i] - i - 1)*(ll)m[i]);
		}
		else
		{
			ans[i] += (n - i - 1)* (ll)m[i];
		}
	}
	return ans;
}
vl solve_ps()
{
	vl ans(n);
	f(i, 0, n)
	{
		ans[i] = m[i];
		if(ps[i] != -1)
		{
			ans[i] += ans[ps[i]];
			ans[i] += ((i - ps[i] - 1)*(ll)m[i]);
		}
		else
		{
			ans[i] += (i)*(ll)m[i];
		}
	}
	return ans;
}
void solution(int t)
{
	cin>>n;
	m.resize(n);
	f(i, 0, n)
		cin>>m[i];
	ns = nxt_sma();
	ps = prev_sma();
	vl ans_ns = solv_ns();
	vl ans_ps = solve_ps();
	// f(i, 0, n)
	// 	cout<<ns[i]<<" ";
	// cout<<endl;
	// f(i, 0, n)
	// 	cout<<ps[i]<<" ";
	// cout<<endl;
	// f(i, 0, n)
	// 	cout<<ans_ns[i]<<" ";
	// cout<<endl;
	// f(i, 0, n)
	// 	cout<<ans_ps[i]<<" ";
	// cout<<endl;
	int ans;
	ll M = 0;
	f(i, 0, n)
	{
		if(ans_ps[i] + ans_ns[i] - m[i] > M)
		{
			M = ans_ps[i] + ans_ns[i] - m[i];
			ans = i;
		}
	}
	vi temp(n);
	temp[ans] = m[ans];
	fre(i, ans - 1, 0)
	{
		if(i+1 < n)
		{
			temp[i] = min(temp[i+1], m[i]);
		}
	}
	f(j, ans+1, n)
	{
		if(j-1>=0)
		{
			temp[j] = min(temp[j-1], m[j]);
		}
	}
	f(i, 0, n)
		cout<<temp[i]<<" ";
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