    #include<stdio.h>
    int main()
      {
        int t,i,x1,x2,y1,y2;
        scanf("%d",&t);
        for(i=1;i<=t;i++)
          {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1==x2 || y1==y2)
              {
                if(x1==x2)
                  {
                    if(y1<y2)
                      printf("up\n");
                    else
                      printf("down\n");
                  }
                else
                  {
                    if(x1<x2)
                      printf("right\n");
                    else
                      printf("left\n");
                  }
              }
            else
              printf("sad\n");
          }
      } 