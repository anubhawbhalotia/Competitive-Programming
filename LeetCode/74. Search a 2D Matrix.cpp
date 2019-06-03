class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(!M)  return false;
        int N = matrix[0].size();
        if(!N)  return false;
        int start = 0, end = M * N - 1;
        while(start < end)
        {
            int mid = (start + end + 1) / 2;
            if(matrix[mid / N][mid % N] < target)
                start = mid + 1;
            else if(matrix[mid / N][mid % N] > target)
                end = mid - 1;
            else
                return true;
        }
        return matrix[end / N][end % N] == target;
    }
};