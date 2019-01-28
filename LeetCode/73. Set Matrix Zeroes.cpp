class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i!=m; i++)
        {
            for(int j=0;j!=n;j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<min(m,n);k++)
                    {
                        
                        matrix[i][k]=(matrix[i][k]==0)?0:-1000;
                        matrix[k][j]=(matrix[k][j]==0)?0:-1000;
                    }
                    for(int k=min(m,n);k<max(m,n);k++)
                    {
                        if(m>n)
                        {
                            matrix[k][j]=(matrix[k][j]==0)?0:-1000;
                        }
                        else
                        {
                            matrix[i][k]=(matrix[i][k]==0)?0:-1000;
                        }
                    }
                }
            }
        
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==-1000)
                    matrix[i][j]=0;
            }
        }
    }
};