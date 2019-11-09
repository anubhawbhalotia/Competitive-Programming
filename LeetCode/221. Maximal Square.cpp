class Solution {
public:
    void display(vector<vector<int>> v)
    {
        cout<<"   ";
        for(int i = 0; i < v[0].size(); i++)
        {
            cout<<i<<" ";
            if(i < 10)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        for(int i = 0; i < v.size(); i++)
        {
            cout<<i<<" ";
            if(i < 10)
            {
                cout<<" ";
            }
            for(int j = 0; j < v[0].size(); j++)
            {
                cout<<v[i][j]<<" ";
                if(v[i][j] < 10)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m;
        if(n)
        {
            m = matrix[0].size();
        }
        else
        {
            return 0;
        }
        vector<vector<int>> a(n, vector<int>(m, 0)), b(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            stack <int> s;
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                {
                    int x = 1;
                    while(!s.empty())
                    {
                        a[i][s.top()] = x++;
                        s.pop();
                    }
                }   
                else
                {
                    s.push(j);
                }
            }
            int x = 1;
            while(!s.empty())
            {
                a[i][s.top()] = x++;
                s.pop();
            }
        }
        // display(a);
        int ans = 0;
        for(int j = 0; j < m; j++)
        {
            stack <int> s;
            for(int i = 0; i < n; i++)
            {
                int x = 1;
                while(!s.empty())
                {
                    if(a[i][j] < a[s.top()][j])
                    {
                        b[s.top()][j] = i - s.top();
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }       
                if(a[i][j] != 0)
                {
                    s.push(i);
                }
            }
            while(!s.empty())
            {
                b[s.top()][j] = n - s.top();
                s.pop();
            }
            // cout<<"b"<<endl;
            // display(b);
        }
        // cout<<"b"<<endl;
        // display(b);
        for(int j = 0; j < m; j++)
        {
            stack <int> s;
            for(int i = n - 1; i >= 0; i--)
            {
                while(!s.empty())
                {
                    if(a[i][j] < a[s.top()][j])
                    {
                        b[s.top()][j] += (s.top() - i - 1);
                        ans = max(ans, min(a[s.top()][j], b[s.top()][j]));
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }       
                if(a[i][j] != 0)
                {
                    s.push(i);
                }
            }
            while(!s.empty())
            {
                b[s.top()][j] += s.top();
                ans = max(ans, min(a[s.top()][j], b[s.top()][j]));
                s.pop();
            }
            // cout<<"b"<<endl;
        }
        // display(b);
        
        return ans*ans;
    }
};