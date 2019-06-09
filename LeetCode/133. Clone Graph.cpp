/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
    Node* cloneGraph(Node* node) {
        unordered_set <Node*> s = {node};
        unordered_map <Node*, Node*> t;
        stack <Node*> m, n;
        vector<Node*> ph;
        Node* root = new Node(node->val, ph), *p, *q, *nb;
        m.push(node);
        n.push(root);
        t[node] = root;
        while(!m.empty())
        {
            p = m.top();
            q = n.top();
            m.pop();
            n.pop();
            f(i, 0, p->neighbors.size())
            {
                nb = p->neighbors[i];
                if(t.find(nb) == t.end())
                    t[nb] = new Node(nb->val, ph);
                q->neighbors.pb(t[nb]);
                if(s.find(nb) == s.end())
                {
                    s.insert(nb);
                    m.push(nb);
                    n.push(t[nb]);
                }
            }
        }
        return root;
    }
};