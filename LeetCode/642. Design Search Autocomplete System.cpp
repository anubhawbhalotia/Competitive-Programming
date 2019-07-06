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
typedef struct node {
    vector <struct node*> c;
    set <pair<int, string>> a;
    node()
    {
        c.resize(27, NULL);
    }
}node;
class trie {
public:
    node *root;
    unordered_map<string, int> m;
    trie()
    {
        root = new node;
    }
    void insertIntoTrie(string &s, int h, node* p)
    {
        bool flag = false;
        if(m.find(s) == m.end())
            m[s] = -h;
        else
        {
            flag = true;
            m[s]--;
        }
        char z;
        f(i, 0, s.length())
        {
            z = (s[i] == ' ') ? 26 : (s[i] - 97);
            if(p->c[z] == NULL)
                p->c[z] = new node;
            if(flag)
                (p->a).erase(p->a.lb({m[s] + 1, s}));                                    
            (p->a).insert({m[s], s});
            p = p->c[z];
        }
        if(flag)
            (p->a).erase(p->a.lb({m[s] + 1, s}));
        (p->a).insert({m[s], s});
    }
    void build(vector <string> &s, vector <int> &h)
    {
        f(i, 0, s.size())
            insertIntoTrie(s[i], h[i], root);
    }
};
class AutocompleteSystem {
    trie t;
    string q;
    node *p;
public:
    AutocompleteSystem(vector<string>& s, vector<int>& h) {
        t.build(s, h); 
        p = t.root;
    }
    vector<string> input(char c) {
        if(c == '#')
        {
            p = t.root;
            t.insertIntoTrie(q, 1, p);
            q = "";
        }
        else
        {
            q += c;
            c = (c == ' ') ? 26 : (c - 97);
        }
        vector <string> ans;
        if(p == NULL || c == '#')
            return ans;
        p = p->c[c];
        if(p == NULL)
            return ans;
        auto it = (p->a).begin();
        int count = 0;
        while(it != (p->a).end() && count++ < 3)
            ans.pb(it++->se);
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */