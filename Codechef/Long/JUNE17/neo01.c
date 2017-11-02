    #include<stdio.h>
    #include<stdlib.h>
    int cmpf (const void * a, const void * b)
    {
       return (*(long long *)a-(*(long long *)b));
    }
    int main()
      {
        int t,tc;
        long long n,i,c1,s1,s2,c2,s,max;
        scanf("%d",&t);
        for(tc=0;tc<t;tc++)
          {
            s=0;
            s1=0;
            s2=0;
            s=0;
            c1=-1;
            max=-1000000000;
            scanf("%lld",&n);
            long long a[n];
            for(i=0;i<n;i++)
              scanf("%lld",&a[i]);
            qsort(a,n,sizeof(long long),cmpf);
           
            for(i=0;i<n;i++)
              {
                if(a[i]<0)
                  {
                    s1=s1+a[i];
                    c1++;
                  }
                else
                  {
                    s2=s2+a[i];
                  }
              }
            c2=n-c1-1;
            if(s2==0)
              {
                //printf("s2==0\n");
                printf("%lld\n",s1);
                continue;
              }
            s=s1+(s2*(c2));
            if(s>max)
              max=s;
            for(i=c1;i>=0;i--)
              {
                s1=s1-a[i];
                s2=s2+a[i];
                c2++;
                s=s1+(s2*(c2));
                if(s>max)
                  max=s;
              }
            printf("%lld\n",max);
          }
      } 