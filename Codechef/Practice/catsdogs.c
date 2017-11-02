    #include<stdio.h>
    int catsdogs(long long c,long long d,long long l)
      {
    	long long legmin=0,legmax=0;
    	legmax=(c+d)*4;
        if(d>=c)
          legmin=4*d;
        else
          {
            if((c-(d*2))>0)
              legmin=(4*d)+((c-(2*d))*4);  
            else
              legmin=(4*d);
          }
        if(l>=legmin && l<=legmax && l%4==0)
          return 0;
        else 
        
          return 1;
      }
            
    	      
    int main()
      {
        long long c,d,l;
        int i,t;
        scanf("%d",&t);
        for(i=0;i<t;i++)
          {
            scanf("%lld %lld %lld",&c,&d,&l);
            catsdogs(c,d,l)==0?printf("yes\n"):(printf("no\n"));
          }
        return 0;
      } 