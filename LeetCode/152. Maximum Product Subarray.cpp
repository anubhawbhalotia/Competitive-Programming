class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = 1, t = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!nums[i])
            {
                t = 1;
                p = 1;
                ans = max(ans, 0);
            }
            else
            {
                p *= nums[i];
                if(p > 0)
                    ans = max(ans, p);
                else
                {
                    if(t == 1)
                    {
                        t = p;
                        ans = max(ans, nums[i]);
                    }
                    else
                        ans = max(ans, p / t);    
                }
            }
        }
        return ans;
    }
};