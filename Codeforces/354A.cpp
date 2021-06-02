#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    int n, l, r, p, q;
    cin>>n>>l>>r>>p>>q;
    vector<int> w(n), a(n);
    f(i, 0, n) {
        cin>>w[i];
        if (i > 0) {
            a[i] = a[i - 1] + w[i];
        } else {
            a[i] = w[i];
        }
    }
    int ans = INT_MAX;
    f(i, -1, n) {
        int cost = 0;
        if (i != -1) {
            cost += (a[i] * l);
        }
        if (i != n - 1) {
            if (i == -1) {
                cost += (a[n - 1] * r);
            } else {
                cost += ((a[n - 1] - a[i]) * r);
            }
        }
        int left_count = i + 1;
        int right_count = n - 1 - i;
        if (left_count > right_count) {
            cost += (left_count - right_count - 1) * p;
        } else if(right_count > left_count) {
            cost += (right_count - left_count - 1) * q;
        }
        ans = min(ans, cost);
    }
    cout<<ans<<endl;
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