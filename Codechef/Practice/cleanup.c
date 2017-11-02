#include<stdio.h>
int main()
  {
    int t,tc,n,m,i,k,c;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++)
      {
        
        scanf("%d %d",&n,&m);
        int a[n+1];
        for(i=0;i<n+1;i++)
          a[i]=0;
        for(i=0;i<m;i++)
          {
            scanf("%d",&k);
            a[k]=-1;
          }
        c=0;
        for(i=1;i<=n;i++)
          {
            if(a[i]==0)
              {
                if(c==0)
                  {
                    printf("%d ",i);
                    c=1;
                  }
                else 
                  c=0;
              }
          }
        c=0;
        printf("\n");
        for(i=1;i<=n;i++)
          {
            if(a[i]==0)
              {
                if(c==1)
                  {
                    printf("%d ",i);
                    c=0;
                  }
                else
                  c=1;
              }
          } 
        printf("\n");
      }
  }