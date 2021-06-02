#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    int v;
    cin>>v;
    vector<int> a(9);
    int m = 0;
    f(i, 0, 9) {
        cin>>a[i];
        if (i > 0) {
            if (a[i] <= a[m]) {
                m = i;
            }
        }
    }
    int d = v / a[m];
    v = v % a[m];
    string ans = "";
    if (d) {
        while(d--) {
            ans += (m + '1');
        }
        int i = 0;
        while(i < ans.length() && v != 0) {
            bool flag = false;
            fre(j, 8, m + 1) {
                if (a[j] - a[m] <= v) {
                    ans[i] = (j + '1');
                    v -= (a[j] - a[m]);
                    flag = true;
                    i++;
                    break;
                }
            }
            if (flag == false) {
                break;
            }
        }
        cout<<ans<<endl;
    } else {
        cout<<"-1"<<endl;
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