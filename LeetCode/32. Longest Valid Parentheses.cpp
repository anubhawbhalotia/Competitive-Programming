class segTree {
    vector<int> t;
public:
    segTree(int n)
    {
        t.resize(n*4 + 1, INT_MAX);
    }
    int update(int x, int v, int node, int l, int r)
    {
        if(x < l || x > r)
            return t[node];
        if(l == r)
        {
            t[node] = v;
            return v;
        }
        t[node] = min(update(x, v, node*2+1, l, (l+r)/2), update(x, v, node*2+2, ((l+r)/2)+1, r));
        return t[node];
    }
    int query(int st, int en, int node, int l, int r)
    {
        if(st > r || en < l)
            return INT_MAX;
        if(l >= st && r <= en)
            return t[node];
        return min(query(st, en, node*2+1, l, (l+r)/2), query(st, en, node*2+2, ((l+r)/2)+1, r));;
    }
};
class Solution {
public:
    int longestValidParentheses(string s) {
        if(!(int)s.length())
            return 0;
        segTree tree((int)s.length());
        unordered_map <int, vector<int>> m;
        unordered_map <char, int> b;
        vector <int> c((int)s.length());
        b['('] = 1;
        b[')'] = -1;
        c[0] = b[s[0]];
        tree.update(0, c[0], 0, 0, (int)s.length() - 1);
        m[0].push_back(-1);
        m[c[0]].push_back(0);
        int temp, ans = 0;
        for(int i = 1; i < (int)s.length(); i++)
        {
            c[i] = c[i-1] + b[s[i]];
            if(s[i] == ')' && m.find(c[i]) != m.end())
            {
                for(int j = 0; j < (int)m[c[i]].size(); j++)
                {
                    if(tree.query(m[c[i]][j] + 1, i - 1, 0, 0, (int)s.length() - 1) >= c[i])
                    {
                        ans = max(ans, i - m[c[i]][j]);
                        break;
                    }
                }
            }
            tree.update(i, c[i], 0, 0, (int)s.length() - 1);
            m[c[i]].push_back(i);
        }
        return ans;
    }
};