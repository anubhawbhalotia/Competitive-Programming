class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> a;
        int p=0,  q=0;
        while(p<m && q<n)
        {
            if(nums1[p] < nums2[q])
            {
                a.push_back(nums1[p]);
                p++;
            }
            else
            {
                a.push_back(nums2[q]);
                q++;
            }
        }
        while(p<m)
        {
            a.push_back(nums1[p]);
            p++;
        }
        while(q<n)
        {
            a.push_back(nums2[q]);
            q++;
        }
        nums1=a;
    }
};  