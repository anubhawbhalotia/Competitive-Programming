class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(nums[mid]>nums[nums.size()-1])
                start=mid+1;
            else
                end=mid;
        }
        int p=start;
        cout<<p<<endl;
        end=nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]<target)
                start=mid+1;
            else if(nums[mid]>target)
                end=mid-1;
            else
                return mid;
        }
        start=0;
        end=p-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]<target)
                start=mid+1;
            else if(nums[mid]>target)
                end=mid-1;
            else
                return mid;
        }
        return -1;
       
    }
};