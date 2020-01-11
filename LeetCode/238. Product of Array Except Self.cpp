class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int> ans(n.size(), 1);
        int temp = 1;
        for(int i = 0; i < (int)n.size() - 1; i++)
        {
            ans[i + 1] = ans[i] * n[i];
        }
        for(int i = (int)n.size() - 1; i > 0; i--)
        {
            temp *= n[i];
            ans[i - 1] *= temp;
        }
        return ans;
    }
};