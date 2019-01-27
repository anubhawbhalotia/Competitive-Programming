class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> v;
        int c=0, val;
        if(matrix.size()==0)
            return v;
        if(matrix.size()<matrix[0].size())
            val=matrix.size();
        else
            val=matrix[0].size();
        
        for(int i=0;i<(val+1)/2;i++)
        {
            for(int j=i; j<matrix[i].size()-i; j++)
            {
                v.push_back(matrix[i][j]);
                c++;
            }
            if(c==0)
                break;
            c=0;
            for(int j=i+1; j<matrix.size()-i; j++)
            {
                v.push_back(matrix[j][matrix[i].size()-i-1]);
                c++;
            }
            if(c==0)
                break;
            c=0;
            for(int j=matrix[i].size()-i-2; j>=i;j--)
            {
                v.push_back(matrix[matrix.size()-i-1][j]);
                c++;
            }
            if(c==0)
                break;
            for(int j=matrix.size()-i-2; j>i;j--)
                v.push_back(matrix[j][i]);
        }
        return v;
    }
};