    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
     
    int main()
    {
     
     
            int t,i,x,y,a,b,c,d,j,k;
            long long count;
     
         scanf("%d",&t);
         for(i=0;i<t;i++)
         {
             count=0;
             scanf("%d %d %d %d",&a,&b,&c,&d);
     
             for(j=a;j<=b;j++)
             {
                if(j>=c)
                break;
                count=count+(d-c)+1;
             }
     
             for(k=j;k<=b;k++)
             {
                 if(k<d)
                    count=count+(d-k);
                 else
                    break;
     
             }
     
     
             printf("%lld\n",count);
         }
     
     
     
         return 0;
    }  