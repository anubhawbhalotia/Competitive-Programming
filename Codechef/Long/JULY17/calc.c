    #include<stdio.h>
    int main()
      {
        int t,tc;
        long n,b,x,xx;
        long long y,max;
        scanf("%d",&t);
        for(tc=0;tc<t;tc++)
          {
            max=0;
            scanf("%ld %ld",&n,&b);
            x=n/b;
            y=n%b;
            xx=(x+1)/2;
            if(x%2==0)
              y=y+(b*xx);
            else
              y=y+(b*(xx-1));
            
            printf("%lld\n",xx*y);
          }
      }
             