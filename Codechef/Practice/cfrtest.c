    #include<stdio.h>
    int main()
      {
      	int z,j,k,c,n;
      	long i,t;
      	scanf("%ld",&t);
      	for(i=0;i<t;i++)
      	  {
      	  	scanf("%d",&n);
      	  	int d[n];
      	  	z=0;
      	  	for(j=0;j<n;j++)
      	  	  scanf("%d",&d[j]);
      	  	for(j=1;j<=100;j++)
      	  	  {
      	  	  	c=0;
    			for(k=0;k<n;k++)
      	  	  	  {
      	  	  	  	if(j==d[k])
      	  	  	  	  {
      	  	  	  	    c=1;
      	  	  	  	    break;
    				  }
    			  }
    			if(c==1)
    			  z++;
    	      }
    	    printf("%d\n",z);
          }
      } 