#include<stdio.h>
int main()
  {
    int t,tc,i,j,c,n,k,temp;
    long long s;
    scanf("%d",&t);
    for(tc=0;tc<t;tc++)
      {
        s=0;
        scanf("%d %d",&n,&k);
        int a[n][k+1];
        int b[n][k];
        int l[n];
        for(i=0;i<n;i++)
          {
            for(j=0;j<k+1;j++)
              a[i][j]=0;
          }
        
        
        for(i=0;i<n;i++)
          {
            scanf("%d",&l[i]);
            fflush(stdin);
            for(j=0;j<l[i];j++)
              {
                scanf("%d",&c);
                a[i][c]=1;
              }
            c=0;
            for(j=1;j<=k;j++)
              {
                if(a[i][j]==0)
                  {
                    b[i][c]=j;
                    c++;
                  }
              }
             b[i][c]=0;
          }
        
        /*printf("n=%d k=%d\n",n,k);
        printf("a[]\n");
        for(i=0;i<n;i++)
          {
            for(j=1;j<=k;j++)
              printf("%d ",a[i][j]);
            printf("\n");
          }
        printf("b[]\n");
        for(i=0;i<n;i++)
          {
            c=0;
            while(b[i][c]!=0)
              {
                printf("%d ",b[i][c]);
                c++;
              }
            printf("%d\n",b[i][c]);
          }
        */
        for(i=1;i<n;i++)
          {
              
            //printf("inside i=%d\n",i);   
            for(j=0;j<i;j++)
              {
                c=0;
               // printf("inside j=%d\n",j);
                if(b[i][0]!=0)
                  {
                   // printf("inside if\n");
                    while(b[i][c]!=0)
                      { 
                      //  printf("entering while\n");
                        temp=b[i][c];
                        if(a[j][temp]==0)
                          break;
                        c++;
                       // printf("exiting while\n");
                      }
                   // printf("outside while\n");
                    if(a[j][temp]!=0)
                      s++;
                  }
                else
                  {
                    s=s+i;
                    break;
                  }
              }
          }
        printf("%lld\n",s);
      }
  }