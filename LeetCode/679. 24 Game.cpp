#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;
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
class Solution {
public:
	string ops = "*/+-";
	vd isValid(int i)
	{
		int f[11];
		vi ans;
		ans.resize(5);
		memset(f, 11, sizeof(f));
		while(i)
		{
			ans.pb(i % 10);
			f[i % 10]++;
			i /= 10;
		}
		if(f[0] == 1 && f[1] == 1 && f[2] == 1 && f[3] == 1)
			ans[4] = 1;
		else
			ans[4] = 0;
	}
    bool judgePoint24(vector<int>& nums) {
		f(i, 0, 3211)
		{
			vd n = isValid(i);
			if(n[4] == 0.0)
				continue;
			f(j, 0, 65)
			{
				int temp = j;
				vi op;
				while(temp)
				{
					op.insert(temp % 4);
					temp /= 4;
				}
				f(k, 0, 3)
				{
					vd newN; //contains 3 digits
					f(t, 0, k)
						newN.pb(n[t]);
					switch(ops[op[k]])
					{
						case '*':
							newN.pb(n[k] * n[k+1]);
							break;
						case '/':
							newN.pb(n[k] / n[k+1]);
							break;
						case '+':
							newN.pb(n[k] + n[k+1]);
							break;
						case '-':
							newN.pb(n[k] - n[k+1]);
					}
					f(t, k+2, 4)
						newN.pb(n[t]);
					vi newop;
					f(t, 0, 3)
					{
						if(t == k)
							continue;
						newop.pb(op[t]);
					}
					f(l, 0, 2)
					{
						vd sfN;
						f(t, 0, l)
							sfN.pb(newN[t]);
						switch(ops[newop[l]])
						{	
							case '*':
								sfN.pb(newN[l] * newN[l+1]);
								break;
							case '/':
								sfN.pb(newN[l] / newN[l+1]);
								break;
							case '+':
								sfN.pb(newN[l] + newN[l+1]);
								break;
							case '-':
								sfN.pb(newN[l] - newN[l+1]);
						}
						f(t, l+2, 3)
							sfN.pb(newN[t]);
						int fop;
						f(t, 0, 2)
						{
							if(t == l)
								continue;
							fop = (newop[t]);
						}
						double ans;
						switch(ops[fop]);
						{
							case '*':
								ans = (sfN[0] * sfN[1]);
								break;
							case '/':
								ans = (sfN[0] / sfN[1]);
								break;
							case '+':
								ans = (sfN[0] + sfN[1]);
								break;
							case '-':
								ans = (sfN[0] - sfN[1]);
						}
						if(abs(ans - 24) < 0.001)
							return true;
					}
				}
			}
		}
		return false;    
    }
};
