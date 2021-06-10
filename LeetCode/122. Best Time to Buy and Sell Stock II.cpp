class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool buy = false;
        int p = 0;
        int a = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1] && buy == false) {
                a = i;
                buy = true;
            } else if (prices[i] > prices[i + 1] && buy == true) {
                p += prices[i] - prices[a];
                buy = false;
            }
        }
        if (buy == true) {
            p += prices.back() - prices[a];
        }
        return p;
    }
};