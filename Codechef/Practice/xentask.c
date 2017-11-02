    #include<stdio.h>
    int main()
      {
        int t,i,j,x,n;
        long xo=0,xe=0,yo=0,ye=0;
        scanf("%d",&t);
        for(i=1;i<=t;i++)
          {
            xo=0,xe=0,yo=0,ye=0;
    		scanf("%d",&n);
            for(j=1;j<=n;j++)
              {
                scanf("%d",&x);
                if(j%2==1)
                  xo=xo+x;
                else
                  xe=xe+x;
              }
            for(j=1;j<=n;j++)
              {
                scanf("%d",&x);
                if(j%2==1)
                  yo=yo+x;
                else
                  ye=ye+x;
              }
            if(yo+xe<xo+ye)
              printf("%d\n",yo+xe);
            else
              printf("%d\n",ye+xo);
          }
        }  