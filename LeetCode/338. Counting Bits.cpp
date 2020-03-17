class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> a(num + 1);
        a[0] = 0;
        int x = 1, c = 0;
        while(x+c <= num)
        {
            if(c < x)
            {
                a[x+c] = a[c] + 1;
                c++;
            }
            else
            {
                c = 0;
                x *= 2;
            }
        }
        return a;
    }
};