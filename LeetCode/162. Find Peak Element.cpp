class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[0] + mid)
                e = mid - 1;
        }
    }
};