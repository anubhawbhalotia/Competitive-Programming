#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
typedef pair<long long ,long long> ptl;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<vector<vector<long long>>> vvvl;
typedef vector<pair<int, int>> vpt;
typedef vector<pair<long long, long long>> vptl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
typedef map<int, int> mi;
typedef map<long long, long long> ml;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>;  
// order_of_key: The number of items in a set that are strictly smaller than k
// find_by_order: It returns an iterator to the ith largest element
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
#define X first
#define Y second
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
int solution(int tc)
{
	int n, k;
	cin>>n>>k;
	vi a(n);
	int h = INT_MAX, flag = 0, count = 0;
	f(i, 0, n)
	{
		cin>>a[i];
		if(a[i] == k)
		{
			count++;
			if(a[i] == h)
				flag = 1;
			if(i > 0)
			{
				if(a[i - 1] > a[i])
					flag = 1;
			}
			if(i > 1)
			{
				if(a[i - 2] >= k)
					flag = 1;
			}
		}
		h = a[i];
	}
	if(flag == 1)
		return 1;
	if(count == 0)
		return 0;
	f(i, 0, n)
	{
		if(a[i] == k)
		{
			if(i < n - 1)
			{
				if(a[i + 1] > a[i])
					return 1;
			}
			if(i < n - 2)
			{
				if(a[i + 2] >= k)
					return 1;
			}
		}
		if(a[i] > k)
		{
			if(i > 0)
			{
				if(a[i - 1] > k)
					return 1;
			}
			if(i < n - 1)
			{
				if(a[i + 1] > k)
					return 1;
			}
			if(i > 1)
			{
				if(a[i - 2] > k)
					return 1;
			}
			if(i < n - 2)
			{
				if(a[i + 2] > k)
					return 1;
			}

		}
	}
	if(n == 1)
	{
		if(a[0] == k)
			return 1;
		else
			return 0;
	}
	// vector<vector<msi>> s(2, vector<msi>(n + 1));
	// int c = 0, x = 0, prev, e, p, q;
	// f(i, 0, n)
	// {
	// 	p = i % 2;
	// 	q = (i + 1) % 2;
	// 	if(a[i] > k)
	// 		x++;
	// 	else if(a[i] < k)
	// 		x--;
	// 	if(a[i] == k)
	// 	{
	// 		c++;
	// 		if(i > 0)
	// 		{
	// 			s[q][c - 1].erase(s[q][c - 1].lb(prev));
	// 		}
	// 	}
	// 	// array [0, i]
	// 	if(i > 0 && c > 0)
	// 	{
	// 		if(i % 2 == 0) // odd length
	// 		{
	// 			if(x >= -(c - 1) && x <= (c - 1))
	// 			{
	// 				return 1;
	// 			}
	// 		}
	// 		else	//even length
	// 		{
	// 			if(x <= c && x >= (2 - c))
	// 			{
	// 				return 1;
	// 			}
	// 		}
	// 	}
	// 	f(j, 0, c)
	// 	{
	// 		e = c - j;
	// 		auto it = s[q][j].lb(x - (e - 1));
	// 		if(it != s[q][j].end())
	// 		{
	// 			if(*it <= (x + (e - 1)))
	// 			{
	// 				return 1;
	// 			}
	// 		}
	// 		//even length
	// 		it = s[p][j].lb(x - e);
	// 		if(it != s[p][j].end())
	// 		{
	// 			if(*it <= (x - (2 - e)))
	// 			{
	// 				return 1;
	// 			}
	// 		}
	// 	}
	// 	if(a[i] == k && i > 0)
	// 	{
	// 		s[q][c - 1].insert(prev);
	// 	}
	// 	s[p][c].insert(x);
	// 	prev = x;
	// }	
	return 0;
}
void testCase()
{
	int tc = 1;
	cin>>tc;
	f(i, 0, tc)
	{
		int ans = solution(i + 1);
		if(ans == 1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		// cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
	}
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    testCase();
}   

