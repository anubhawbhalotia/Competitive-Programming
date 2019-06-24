#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef set<int> si;
typedef set<long long> sl;
typedef unordered_set <int> usi;
typedef unordered_set <long long> usl;
typedef multiset<int> msi;
typedef multiset<long long> msl;
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
int n, m;
class small {
public:
	vi t;
	small()
	{
		t.resize(3*m);
	}
	void build(vi &a, int node = 0, int st = 0, int en = m - 1)
	{
		if(st == en)
		{
			t[node] = a[st];
			return ;
		}
		build(a, node*2+1, st, (st + en) / 2);
		build(a, node*2+2, (st + en) / 2 + 1, en);
		t[node] = t[node*2+1] + t[node*2+2];
	}
	int query(int l, int r, int node = 0, int st = 0, int en = m - 1)
	{
		if(l > en || r < st)
			return 0;
		if(st >= l && en <= r)
			return t[node];
		return query(l, r, node*2+1, st, (st + en) / 2) + 
			query(l, r, node*2+2, (st + en) / 2 + 1, en);
	}
	void update(int index, int val, int node = 0, int st = 0, int en = m - 1)
	{
		if(index < st || index > en)
			return ;
		if(st == en)
        {
			t[node] = val;
            return ;
        }
		update(index, val, node*2+1, st, (st + en) / 2);
		update(index, val, node*2+2, (st + en) / 2 + 1, en);
		t[node] = t[node*2+1] + t[node*2+2];
	}
};
class large {
public:
    vector <small> t;
    void constr()
    {
        t.resize(3*n);
    }
	void build(vector <small> &sTree, int node = 0, int st = 0, int en = n - 1)
	{
		if(st == en)
		{
            t[node] = sTree[st];
			return ;
		}
		build(sTree, node*2+1, st, (st + en) / 2);
		build(sTree, node*2+2, (st + en) / 2 + 1, en);
		f(i, 0, 3*m)
			t[node].t[i] = t[node*2+1].t[i] + t[node*2+2].t[i];
	}
	int query(int large_l, int large_r, int small_l, int small_r, int node = 0, 
		int st = 0, int en = n - 1)
	{
		if(large_l > en || large_r < st)
			return 0;
		if(st >= large_l && en <= large_r)
			return t[node].query(small_l, small_r);
        return query(large_l, large_r, small_l, small_r, node*2+1, st, 
        	(st + en) / 2) +
			query(large_l, large_r, small_l, small_r, node*2+2, 
				(st + en) / 2 + 1, en);
	}
	void update(int large_ind, int small_ind, int val, int node = 0, int st = 0,
		int en = n - 1)
	{
		if(large_ind < st || large_ind > en)
			return ;
		if(st == en)
        {
			t[node].update(small_ind, val);
            return ;
        }
		update(large_ind, small_ind, val, node*2+1, st, (st + en) / 2);
		update(large_ind, small_ind, val, node*2+2, (st + en) / 2 + 1, en);
		f(i, 0, 3*m)
			t[node].t[i] = t[node*2+1].t[i] + t[node*2+2].t[i];
	}
};
class NumMatrix {
public:
    large lTree;
    NumMatrix(vector<vector<int>>& a) {
        n = a.size();
        if(n)
            m = a[0].size();
        else
            return ;
        vector <small> sTree(n);
        lTree.constr();
        f(i, 0, n)
        	sTree[i].build(a[i]);
        lTree.build(sTree);
    }
    void update(int row, int col, int val) {
     	lTree.update(row, col, val);   
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return lTree.query(row1, row2, col1, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */