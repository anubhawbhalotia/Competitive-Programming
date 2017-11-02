    #include<stdio.h>
    int main()
      {
        long t,i,n,c,d,s,j; 
        scanf("%ld",&t);
        for(i=0;i<t;i++)
          {
            scanf("%ld",&n);
            c=n;
            d=0;
            while(c!=0)
              {
                c=c/10;
                d++;
              }
            d--;
            s=1;
            for(j=1;j<=d;j++)
              s=s*10;
            if(n<0)
              {
                s=s+(2*n*(-1));
              }
            printf("%ld\n",s);
          }
      } 