        #include<stdio.h>
    long gp(long r,long n,long m)
      {
        long res=1,x,y,res1;
        if(n==1)
          return 1;
        if(n==0)
          return 0;
        x=r;     
        y=2;
        while (y > 0)
          {
            if (y & 1)
              res = (res*x)%m;
            y = y>>1; 
            x = (x*x)%m;  
        }
        if(n%2==0)
          return ((1+r)*gp(res,n/2,m))%m;
        else
          {
            x=r;
            y=n-1;
            res1=1;
            while (y > 0)
              {
                if (y & 1)
                  res1 = (res1*x)%m;
                y = y>>1; 
                x = (x*x)%m;  
              }
            return ((((1+r)*gp(res,n/2,m))%m)+((res1)%m))%m;
          }
      }
    int main()
      {
        long a,d,r,n,m,z,c,x,y,res,i;
        int t,tc;
        scanf("%d",&t);
        for(tc=0;tc<t;tc++)
          {
            scanf("%ld %ld %ld %ld %ld",&a,&d,&r,&n,&m);
            z=(d*gp(r,n/2,m))%m;
            c=(n/2)-1;
            x=r;
            y=c;
            res=1;
            while (y > 0)
              {
                if (y & 1)
                res = (res*x)%m;
                y = y>>1; 
                x = (x*x)%m;  
              }
            z=(z+(res*a)%m)%m;
            if(n%2==1 && n!=1)
              z=(z*r)%m;
            printf("%ld\n",z);
        }
      } 