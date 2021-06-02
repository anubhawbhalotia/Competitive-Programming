#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int dfs(int root, vector<vector<int>> &adj, vector<int> &c, vector<int> &parent, map<pair<int,int>,int> &edges, vector<int> &ans) {
    int total_sum = 0;
    for (int i = 0; i < adj[root].size(); i++) {
        if (adj[root][i] != parent[root]) {
            int sum = dfs(adj[root][i], adj, c, parent, edges, ans);
            ans[edges[{min(root, adj[root][i]), max(root, adj[root][i])}]] += sum;
            total_sum += sum;
        }
    }
    total_sum += c[root];
    return total_sum;
}
int solution(int tc) {
    int n;
    cin>>n;
    map<pair<int, int>, int> edges;
    vector<vector<int>> adj(n);
    int u, v;
    f(i, 0, n - 1) {
        cin>>u>>v;
        u--;
        v--;
        edges.insert({{min(u, v), max(u, v)}, i});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // store parent and level of each node considering root as node 0
    // store parent matrix
    vector<int> parent(n), level(n);
    vector<vector<int>> s(n, vector<int> (20, -1)); // parent matrix
    int root = 0;
    parent[root] = -1;
    queue<int> q;
    q.push(root);
    int dis = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int head = q.front();
            level[head] = dis;
            q.pop();
            s[head][0] = parent[head];
            int curr = s[head][0];
            int i = 1;
            while(curr != -1) {
                s[head][i] = s[curr][i - 1];
                curr = s[head][i];
                i++;
            }
            for (int i = 0; i < adj[head].size(); i++) {
                if (adj[head][i] != parent[head]) {
                    q.push(adj[head][i]);
                    parent[adj[head][i]] = head;
                }
            }
        }
        dis++;
    }
    // queries
    int k;
    cin>>k;
    vector<int> c(n, 0);
    f(i, 0, k) {
        cin>>u>>v;
        u--;
        v--;
        if (level[u] > level[v]) {
            swap(u, v);
        }
        c[u]++;
        c[v]++;
        // find lca
        int diff = level[v] - level[u];
        int x = 0;
        while(diff) {
            if (diff % 2 == 1) {
                v = s[v][x];
            }
            x++;
            diff /= 2;
        }
        // now u and v are at same level
        // final finding lca
        while(u != v) {
            x = 0;
            while(s[u][x] != s[v][x]) {
                u = s[u][x];
                v = s[v][x];
                x++;
            }
            if (s[u][0] == s[v][0]) {
                u = s[u][0];
                v = s[v][0];
            }
        }
        c[u] -= 2;
    }

    // calculating answer
    // dfs
    vector<int> ans(n - 1, 0);
    dfs(root, adj, c, parent, edges, ans);
    f(i, 0, n - 1) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 1;
}

void testCase() {
    int tc = 1;
    // cin>>tc;
    f(i, 0, tc) {
        solution(i + 1);
        // cout<<\"Case #\"<<i + 1<<\": \"<<solution(i + 1)<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testCase();
}