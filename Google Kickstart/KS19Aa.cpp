#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long n, p;
    cin>>t;
    for(int j = 1; j<=t; j++)
    {
        scanf("%ld %ld",&n,&p);
        long a[n+1];
        long s = 0, min;
        for(long i = 0; i < n; i++)
            scanf("%ld",&a[i]);
        sort(a, a+n);
        for(long i = 0; i<p-1; i++)
            s = s + (a[p-1] - a[i]);
        min = s;
        for(long i = p-1; i < n-1; i++)
        {
            s = s - (a[i] - a[i-p+1]);
            s = s + ((a[i+1] - a[i]) * (p-1));
            if(s<min)
                min = s;
        }
        printf("Case #%d: %lld\n",j,min);
    }
}