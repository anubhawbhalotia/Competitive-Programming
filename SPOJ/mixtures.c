    #include<stdio.h>
    long sum(int n,int *a,int low,int high,long *pref)
      {
        if(low==0)
          return *(pref+high);
        else
          return(*(pref+high)-*(pref+low-1));
      }
    long long dp(int n,int *a,long long *b,int low,int high,long *pref)
      {
        long long min,smoke,p1,p2;
        long s1,s2;
        int j;
        if(*(b+(n*low)+high)!=-1)
          return *(b+(n*low)+high);
        if(low==high)
          return 0;
        min=1000000000000000000;    
        for(j=low;j<high;j++)
          {
            p1=dp(n,a,b,low,j,pref);
            p2=dp(n,a,b,j+1,high,pref);
            s1=sum(n,a,low,j,pref);
            s2=sum(n,a,j+1,high,pref);
            smoke=p1+p2+((s1%100)*(s2%100));
            if(smoke<min)
              min=smoke;
         }
        *(b+(n*low)+high)=min;
        return min;
      }
    int main()
      {
        int n,i,j;
        while(scanf("%d",&n)!=EOF)
          {
            int a[n];
            long pref[n];
            long long b[n][n];
            for(i=0;i<n;i++)
              {
                for(j=0;j<n;j++)
                  b[i][j]=-1;
              }
            for(i=0;i<n;i++)
              scanf("%d",&a[i]);
            pref[0]=a[0];
            for(i=1;i<n;i++)
              pref[i]=pref[i-1]+a[i];
            dp(n,a,b[0],0,n-1,pref);
            if(n==1)
              printf("0\n");
            else
              printf("%lld\n",b[0][n-1]);
          }
      } 