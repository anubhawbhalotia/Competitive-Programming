#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
string itoa_custom(int a) {
    string ans = "";
    while(a) {
        ans += ((a % 10) + '0');
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int solution(int tc) {
    int n;
    cin>>n;
    string a;
    vector<string> b;
    f(i, 0, n) {
        cin>>a;
        if (a.length() <= 10) {
            b.push_back(a);
        } else {
            b.push_back(a[0] + itoa_custom((int)a.length() - 2) + a[a.length() - 1]);
        }
    }
    f(i, 0, b.size()) {
        cout<<b[i]<<endl;
    }
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