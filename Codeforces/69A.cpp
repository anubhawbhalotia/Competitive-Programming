#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    int n, a, b, c, d = 0, e = 0, f = 0;
    cin>>n;
    f(i, 0, n) {
        cin>>a>>b>>c;
        d += a;
        e += b;
        f += c;
    }
    if (d == 0 && e == 0 && f == 0) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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