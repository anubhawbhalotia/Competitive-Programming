    #include<stdio.h>
    int main()
      {
        int n,q,i,ans[100001];
        long min=0,max=0,ele[100001],b;
        scanf("%d %d",&n,&q);
        scanf("%ld",&ele[0]);
        min=ele[0];
        max=ele[0];
        for(i=1;i<n;i++)
          {
            scanf("%ld",&ele[i]);
            if(ele[i]<min)
              min=ele[i];
            else if(ele[i]>max)
              max=ele[i];
          }
        for(i=0;i<q;i++)
          {
            scanf("%d",&b);
            if(b>=min && b<=max)
              ans[i]=1;
            else
              ans[i]=0;
          }
        for(i=0;i<q;i++)
          {
            if(ans[i]==0)
              printf("No\n");
            else 
              printf("Yes\n");
          }
      }  