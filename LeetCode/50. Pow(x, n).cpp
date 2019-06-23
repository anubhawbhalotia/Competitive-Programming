class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long z = n;
        long c = abs(z);
        while(c)
        {
            long t = 2; 
            double temp = x;
            while(t < c)
            {
                temp *= temp;
                t*=2;
            }
            t /= 2;
            c-=t;
            ans *= temp;
        }
        if(z < 0)
            ans = 1.0 / ans;
        return ans;  
    }
};