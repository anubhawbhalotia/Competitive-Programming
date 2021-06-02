#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)

int solution(int tc) {
    int n, m;
    cin>>n>>m;
    int s = -1, e;
    vector<int> a(n);
    vector<pair<int, int>> r;
    f(i, 0, n) {
        cin>>a[i];
        if (i > 0 && a[i] < a[i - 1]) {
            s = i - 1;
        } else if(i > 0 && a[i] > a[i - 1]) {
            if (s != -1) {
                r.push_back({s, i});
                s = -1;
            }
        }
    }
    vector<pair<pair<int, int>, int>> q;
    f(i, 0, m) {
        cin>>s>>e;
        s--;
        e--;
        q.push_back({{s, e}, i});
    }
    sort(q.begin(), q.end());
    int p = 0, i = 0, j = 0;
    vector<string> ans(m, "Yes");
    while(i < m && j < r.size()) {
        if (q[i].first.first <= r[j].first) {
            if (q[i].first.second >= r[j].second) {
                ans[q[i].second] = "No";
            }
            i++;
        } else {
            j++;
        }
    }
    f(i, 0, m) {
        cout<<ans[i]<<endl;
    }
    return 1;
}
void testCase() {
    int tc = 1;
    // cin>>tc;
    f(i, 0, tc) {
        solution(i + 1);
        // cout<<"Case #"<<i + 1<<": "<<solution(i + 1)<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testCase();
}