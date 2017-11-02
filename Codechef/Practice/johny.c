    #include<stdio.h>
    #include<stdlib.h>
    int cmpf (const void * a, const void * b)
    {
       return (*(long*)a-(*(long*)b));
    }
    int main()
      {
        int t,tc,n,i,k,c;
        scanf("%d",&t);
        for(tc=1;tc<=t;tc++)
          {
            scanf("%d",&n);
            long a[n];
            for(i=0;i<n;i++)
              scanf("%ld",&a[i]);
            scanf("%d",&k);
            c=a[k-1];
            qsort(a,n,sizeof(long),cmpf);
            for(i=0;i<n;i++)
              {
                if(a[i]==c)
                  break;
              }
            printf("%d\n",i+1);
          }
      } 