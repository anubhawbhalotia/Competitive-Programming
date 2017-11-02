    #include<stdio.h>
    #include<math.h>
    int main()
      {
        int t,i;
        int a,b;
        scanf("%d",&t);
        for(i=1;i<=t;i++)
          {
            scanf("%d %d",&a,&b);
            a=sqrt(a);
            b=(sqrt(1+(4*b))-1)/2;
            if(a<=b)
              printf("Bob\n");
            else
              printf("Limak\n");
          }
      } 