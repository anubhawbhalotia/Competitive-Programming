    #include<stdio.h>
    int studvote(int n,int k)
      {
        int i,j,a[101],b=0,c;
        for(i=1;i<=n;i++)
          {
            scanf("%d",&a[i]);
            if(i==a[i])
              a[i]=0;
          }
        for(i=1;i<=n;i++)
          {
            if(a[i]==0)
              continue;
    		c=0;
    		for(j=1;j<=n;j++)
              {
                if(a[j]==i)
                  c++;
              }
            if(c>=k)
              b++;
          }
        return b;
      }
                  
    int main()
      {
        int t,n,k,i;
        scanf("%d",&t);
        for(i=0;i<t;i++)
          {
            scanf("%d %d",&n,&k);
            printf("%d\n",studvote(n,k));
          }
        return 0;
      } 