    #include<stdio.h>
    long int chefkey(long n,long m,long c)
      {
        long i,z=0;
        for(i=1;i<=n;i++)
          {
            if(c/i<=m && c%i==0)
              z++;
          }
        return z;
      }
    int main()
      {
        int t,i;
    	long n,m,c,a[100];
    	scanf("%d",&t);
    	for(i=0;i<t;i++)
    	  {
    	    scanf("%ld %ld %ld",&n,&m,&c);
    	    a[i]=chefkey(n,m,c);
    	  }
    	for(i=0;i<t;i++)
    	  printf("%ld\n",a[i]);
    	return 0;
      } 