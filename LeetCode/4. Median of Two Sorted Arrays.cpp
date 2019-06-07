class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        int m = n1.size(), n = n2.size(), p = (m + n - 1) / 2;
        if(m == 0)
            return (n2[n / 2] + n2[(n - 1) / 2]) / 2.0;
        if(n == 0)
            return (n1[m / 2] + n1[(m - 1) / 2]) / 2.0;
        int l = max(-1, p - n - 1), r = min(p - 1, m - 1);
        while(l < r)
        {
            int mid = floor((l + r) / 2.0);
            if(mid + 1 < m && mid != (p - 1))
            {
                if(n1[mid + 1] < n2[p - (mid + 1) - 1])
                {
                    l = mid + 1;
                    continue;
                }
            }
            if(p - (mid + 1) < n && mid != -1)
            {
                if(n2[p - (mid + 1)] < n1[mid])
                {
                    r = mid - 1;
                    continue;
                }
            }
            r = mid;
        }
        multiset <int> s;
        for(int i = l + 1; i < min(m, l + 3); i++)
            s.insert(n1[i]);
        for(int i = p - (l + 1); i < min(p - (l + 1) + 2, n); i++)
            s.insert(n2[i]);
        if((m + n) % 2 == 1)
            return *s.begin();
        else
            return (*s.begin() + *(++s.begin())) / 2.0;
    }
};