#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define beg(x) x.begin()
#define en(x) x.end()
#define f(i,s,n) for(long i=s;i<n;i++)
#define fe(i,s,n) for(long i=s;i<=n;i++)
#define fr(i,s,n) for(long i=s;i>n;i--)
#define fre(i,s,n) for(long i=s;i>=n;i--)
#define mod 998244353
const ll INF_ll = 1e18;
const ll INF_l = 1e6 + 1;
//Anubhaw Bhalotia https://github.com/anubhawbhalotia
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<int,double> pid;
typedef pair<string,int> psi;
typedef pair<long,long> pl;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<long> sl;
typedef set<ll> sll;
typedef multiset<int> msi;
typedef multiset<long> msl;
typedef multiset<ll> msll;
typedef set <pid> spsd;
class bst {
    typedef struct node {
        int data;
        int c;
        struct node *left, *right, *parent;
        node()
        {   
            c = 0;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
    }node;
    node *root;
    node* insert(int val)
    {
        node *p = root, *ans;
        if(p == NULL)
        {
            root = new node;
            root->data = val;
            return root;
        }
        else
        {
            stack <node*> s;
            while(1)
            {
                s.push(p);
                if(val > p->data)
                {
                    if(p->right != NULL)
                        p = p->right;
                    else
                    {
                        p->right = new node;
                        p->right->data = val;
                        p->right->parent = p;
                        p->right->c = 0;
                        ans = p->right;
                        break;
                    }
                }
                else
                {
                    if(p->left != NULL)
                        p = p->left;
                    else
                    {
                        p->left = new node;
                        p->left->data = val;
                        p->left->parent = p;
                        p->left->c = 0;
                        ans = p->left;
                        break;
                    }
                }
            }
            while(!s.empty())
            {
                s.top()->c += 1;
                s.pop();
            }
        }
        return ans;
    }
    int cntles(node* p)
    {
        int ans = 0;
        while(p != root)
        {
            if(p->parent->right == p)
            {
                ans += 1;
                if(p->parent->left != NULL)
                    ans += p->parent->left->c + 1;
                p = p->parent;
            }
            else
                p = p->parent;
        }
        return ans;
    }
public:
    bst()
    {
        root = NULL;
    }
    int findAns(int val)
    {
        node *p = insert(val);
        return cntles(p);
    }
};
class Solution {
    vector <pair <int, int> > v[100000];
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector <int> ans;
        if(nums.size() == 0)
            return ans;
        ans.resize(nums.size());
        bst tree;
        fre(i, nums.size() - 1, 0)
            ans[i] = tree.findAns(nums[i]); 
        return ans;
    }
};