class Solution {
public:
    int s = 0, e = -1;
    string reverseWords(string st) {
        for(int i = 0; i < st.length(); i++)
        {
            if(st[i] == ' ')
            {
                for(int j = s; j <= (s+e-1)/2; j++)
                {
                    swap(st[j], st[e-(j-s)]);
                }
                s = i + 1;
            }
            e++;
        }
        for(int j = s; j <= (s+e-1)/2; j++)
        {
            swap(st[j], st[e-(j-s)]);
        }
        return st;
    }
};