#include <bits/stdc++.h>
using namespace std;
#define f(i,s,n) for(int i = s; i < n; i++)
#define fe(i,s,n) for(int i = s; i <= n; i++)
#define fr(i,s,n) for(int i = s; i > n; i--)
#define fre(i,s,n) for(int i = s; i >= n; i--)
int solution(int tc) {
    int n;
    cin>>n;
    vector<string> a(n);
    f(i,0, n) {
        cin>>a[i];
    }
    f(i, 1, n - 1) {
        f(j, 1, n - 1) {
            if(a[i][j] == '#' && a[i - 1][j] == '#' && a[i + 1][j] == '#' && a[i][j - 1] == '#' & a[i][j + 1] == '#') {
                a[i][j] = '.';
                a[i-1][j] = '.';
                a[i+1][j] = '.';
                a[i][j-1] = '.';
                a[i][j+1] = '.';
            } 
        }
    }
    bool ans = true;
    f(i, 0, n) {
        f(j, 0, n) {
            if (a[i][j] == '#') {
                ans = false;
                break;
            }
        }
    }
    if (ans) {
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