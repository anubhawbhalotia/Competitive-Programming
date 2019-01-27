class Solution {
public:
    void sortColors(vector<int>& nums) {
        int  a=0,  b=nums.size()-1, temp, i=0;
        while(i<=b)
        {
            if(nums[i]==0)
            {
                nums[i]=nums[a];
                nums[a]=0;
                a++;
            }
            else if(nums[i]==2)
            {
                nums[i]=nums[b];
                nums[b]=2;
                b--;
            }
            if(i<a || nums[i]==1)
                i++;
        }
    }
};