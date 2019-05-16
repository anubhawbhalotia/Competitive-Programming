class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int  e, j, n = 0;
        int a[] = {0, 192, 224, 240};
        int b[] = {128, 32, 16, 8};
        for(int i = 0; i != data.size(); i++)
        {
            e = data[i] % 256;
            if(n == 0)
            {
                for(j = 0; j<4; j++)
                {
                    if((e & a[j]) == a[j] && (e & b[j]) == 0)
                    {
                        n = j;
                        break;
                    }
                }
                if(j == 4)
                    return false;
            }
            else
            {
                if((e & 128) == 128 && (e & 64) == 0)
                    n--;
                else
                    return false;
            }
        }
        if(n)
            return false;
        else
            return true;
    }
};