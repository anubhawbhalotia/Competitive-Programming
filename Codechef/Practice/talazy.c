    #include<stdio.h>
    long long talazy(long long n,long long b,long long m)
      {
        long long t=0;
    	while(1)
          {
            if(n==0)
              break;        
            if(n%2==0)
              t=t+(m*(n/2))+b;
            else
              t=t+(m*(n+1)/2)+b;
            n=n/2;
            m=m*2;
          }
        return t-b;
      }
            
    int main()
      {
        int t,i;
        long long n,b,m;
        scanf("%d",&t);
        for(i=0;i<t;i++)
          {
            scanf("%lld %lld %lld",&n,&b,&m);
            printf("%lld\n",talazy(n,b,m));
          }
      } 