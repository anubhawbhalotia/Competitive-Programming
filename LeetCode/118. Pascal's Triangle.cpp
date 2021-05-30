class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        vector<int> b;
        b.push_back(1);
        a.push_back(b);
        for (int i = 1; i < numRows; i++) {
            vector<int> b;
            b.push_back(a[i - 1][0]);
            for (int j = 0; j < a[i - 1].size() - 1; j++) {
                b.push_back(a[i - 1][j] + a[i - 1][j + 1]);
            }
            b.push_back(a[i - 1][a[i - 1].size() - 1]);
            for (int j = 0; j < b.size(); j++) {
                cout<<b[j]<<" ";
            }
            cout<<endl;
            a.push_back(b);
        }
        return a;
    }
};