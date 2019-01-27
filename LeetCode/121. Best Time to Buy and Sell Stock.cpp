class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        int minVal = prices[prices.size()-1];
        int maxVal = 0;
        for(int i=prices.size()-2; i>=0; i--)
        {
            if(minVal-prices[i]>maxVal)
                maxVal = minVal - prices[i];
            if(prices[i]>minVal)
                minVal=prices[i];
            
        }
        return maxVal;
        
    }
};