class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = -10000, ans = 0;
        for(int i = 0; i!=nums.size(); i++)
        {
            if(nums[i]!=curr)
            {
                curr = nums[i];
                ans++;
                continue;
            }
            nums[i] = -9999;
        }
        int j = -1, temp;
        for(int i = 0;i!=nums.size(); i++)
        {
            if(nums[i]!=-9999)
            {
                j++;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        return ans;
    }
};