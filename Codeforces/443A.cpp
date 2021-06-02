#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    string a;
    getline(cin, a);
    // cout<<a<<endl;
    int ans = 0;
    // 1, 4, 7
    // cout<<a.length()<<endl;
    vector<bool> c(300, false);
    for (int i = 1; i < a.length() && a.length() > 2; i += 3) {
        // cout<<a[i]<<endl;
        if (c[a[i]] == false) {
            c[a[i]] = true;
            ans++;
        }
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