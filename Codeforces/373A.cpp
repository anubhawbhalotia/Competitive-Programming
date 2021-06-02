#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    int k;
    cin>>k;
    char c;
    vector<int> a(200,0);
    f(i, 0, 4) {
        f(j, 0, 4) {
            cin>>c;
            a[c]++;
        }
    }
    bool ans = true;
    for (char i = '1'; i <= '9'; i++) {
        if (a[i] > (2 * k)) {
            ans = false;
            break;
        }
    }
    if(ans) {
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