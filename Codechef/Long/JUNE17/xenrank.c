    #include<stdio.h>
    int main()
      {
        int t,tc;
        long long u,v;
        long long s;
        scanf("%d",&t);
        for(tc=1;tc<=t;tc++)
          {
            s=0;
            scanf("%lld %lld",&u,&v);
            s=((u+v)*(u+v+1))/2;
            s=s+u+1;
            printf("%lld\n",s);
          }
      } 