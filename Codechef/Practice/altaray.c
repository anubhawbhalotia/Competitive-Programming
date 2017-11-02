    #include<stdio.h>
    int main()
      {
      	int t,i;
      	long long n,j,c,k,l;
    	scanf("%d",&t);
      	for(i=0;i<t;i++)
      	  {
      	  	scanf("%lld",&n);
      	  	long long a[n];
      	  	for(j=0;j<n;j++)
      	  	  scanf("%lld",&a[j]);
      	  	for(j=0;j<n;j++)
      	  	   {
      	  	   	c=1;
      	  	   	l=j;
    			for(k=l;k<n-1;k++)
      	  	   	  {
      	  	   	  	if((a[k+1]*a[k])<0)
      	  	   	  	  {
      	  	   	  	    c++;
      	  	   	  	    j++;
      	  	   	      }
      	  	   	  	else
      	  	   	  	  break;
    			  }
    			for(;c>0;c--)
    			printf("%lld ",c);
    		   }
    		printf("\n");
    		}
      } 