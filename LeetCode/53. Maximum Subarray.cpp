class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long ans=0, maxVal = -2147483648;
        for(int i=0;i!=nums.size();i++)
        {
            ans+=nums[i];
            if(ans>maxVal)
                maxVal=ans;
            if(ans<0)
            {
                ans=0;
                continue;
            }
        }
        return maxVal;
    }
};