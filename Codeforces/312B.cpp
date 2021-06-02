#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    double a, b, c, d;
    cin>>a>>b>>c>>d;
    double ans = 1 / (1 - ((b-a)*(d-c)/(b*d)));
    ans *= (a/b);
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