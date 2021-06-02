#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    int n;
    cin>>n;
    int ans = 0;
    ans = (n / 2) * n;
    if (n % 2 == 1) {
        ans += ((n + 1) / 2);
    }
    cout<<ans<<endl;
    string a;
    f(i, 0, n) {
        a = "";
        f(j, 0, n) {
            if ((i + j) % 2 == 0) {
                a += 'C';
            } else {
                a += '.';
            }
        }
        cout<<a<<endl;
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