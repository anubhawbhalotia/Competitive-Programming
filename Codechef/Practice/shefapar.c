#include<stdio.h>
int main()
  {
  	int t,c,i,x;
  	long n,s=0,j;
  	scanf("%d",&t);
  	for(i=0;i<t;i++)
  	  {
  	  	scanf("%ld",&n);
  	  	c=0;
  	  	s=0;
  	  	for(j=1;j<=n;j++)
  	  	{
  	  		scanf("%d",&x);
  	  		if(x==0)
  	  		  {
				s=s+1000;
				c=1;
		      }
		    if(c==1)
		      {
		      	s=s+100;
			  }
	    }
	    printf("%ld\n",s);
      }
  }