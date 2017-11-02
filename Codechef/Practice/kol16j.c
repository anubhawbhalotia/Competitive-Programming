    #include<stdio.h>
    int seq(int*,int);
    int check(int*,int);
    int exhaust(int*,int);
    int rep(int*,int);
    void display(int*,int);
    int main()
      {
        int i,j,ans=0,a[100],t,b[100],n;
        scanf("%d",&t);
        for(i=0;i<t;i++)
          {
            scanf("%d",&n);
            for(j=0;j<n;j++)
              scanf("%d",&a[j]);
            ans=check(a,n);
            b[i]=ans;
          }
        display(b,t);
        return 0;
      }
    void display(int *b,int t)
      {
        int i;
        for(i=0;i<t;i++)
          {
            if(*(b+i)==0)
              printf("no\n");
            else
              printf("yes\n");
          }
      }
    int check(int *a,int n)
      {
        if(seq(a,n)==1 && exhaust(a,n)==1 && rep(a,n)==1)
          return 1;
        else
          return 0;
      }
    int seq(int *a,int n)
      {
        int i;
        for(i=1;i<=n;i++)
          {
            if(*(a+i-1)!=i)
              break;
          }
        if(i>n)
          return 0;
        else
          return 1;
      }
    int exhaust(int *a,int n)
      {
        int i,j;
        for(i=1;i<=n;i++)
          {
            for(j=0;j<n;j++)
              {
                if(i==*(a+j))
                  break;
              }
            if(j>=n)
              return 0;
          }
        return 1;
      }
    int rep(int *a,int n)
      {
        int i,j,c;
        for(i=1;i<=n;i++)
          {
            c=0;
            for(j=0;j<n;j++)
              {
                if(i==*(a+j))
                  c++;
              }
            if(c>1)
              return 0;
          }
        return 1;
      } 