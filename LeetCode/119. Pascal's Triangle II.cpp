// Time : O(n)
// Space : O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a;
        a.push_back(1);
        int prev, temp;
        for (int i = 0; i < rowIndex; i++) {
            prev = 1;
            for (int j = 1; j < a.size(); j++) {
                temp = a[j];
                a[j] = prev + a[j];
                prev = temp;
            }
            a.push_back(1);
        }
        return a;
    }
};