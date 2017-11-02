    #include<stdio.h>
    int main()
      {
      	
      	  	int l,i,j=0,k,tc,kc,t[10],d[10],n,c;
      	  	long s;
      	  	scanf("%d",&tc);
      	  	for(kc=0;kc<tc;kc++)
      	  	  {
      	  	  	c=0;
      	  	  	s=0;
    		    scanf("%d %d",&n,&k);
      	  	  	for(i=0;i<n;i++)
      	  	  	  scanf("%d %d",&t[i],&d[i]);
      	  	  	i=0;
      	  	  	j=0;
      	  	  	if(k!=0)
      	  	  	{
    	        for(i=0;i<n;i++)
    		      {
    		  	    for(j=1;j<=t[i];j++)
    		  	      {
    		  	  	    c++;
    		  	  	    if(c==k)
    		  	  	      break;
    				  }
    			    if(c==k)
    			      break;
    		      }
    		   }
    		    s=s+(d[i]*(t[i]-j));
                for(l=i+1;l<n;l++)
    			  {
    			  	s=s+(d[l]*t[l]);
    			  }	
    			printf("%ld\n",s);	    
    		
    		}
      } 