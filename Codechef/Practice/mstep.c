    #include<stdio.h>
    #include<math.h>
    int main()
      {
      	int t,tc,i,j,n;
      	long long s;
      	scanf("%d",&t);
      	for(tc=1;tc<=t;tc++)
      	  {
      	  	scanf("%d",&n);
      	  	long long a[n][n],r[(n*n)+1],c[(n*n)+1];
      	  	s=0;
      	  	for(i=0;i<n;i++)
      	  	  {
      	  	  	for(j=0;j<n;j++)
      	  	  	  {
      	  	  	  	scanf("%lld",&a[i][j]);
      	  	  	  	r[a[i][j]]=i;
      	  	  	  	c[a[i][j]]=j;
      	  	  	  	
    			  }
    		  }
    		for(i=1;i<(n*n);i++)
    		  {
    	
    			s=s+abs(r[i+1]-r[i])+abs(c[i+1]-c[i]);
    		  }
    		printf("%lld\n",s);
    	  }
      } 