#include<stdio.h>
#include<string.h>
int main()
  {
  	int t,n,i,j,c=0,ans=0;
  	char ch[7];
  	scanf("%d",&t);
  	for(i=1;i<=t;i++)
  	  {
  	  	scanf("%d",&n);
  	  	c=0;
  	  	ans=0;
  	  	for(j=1;j<=n;j++)
  	  	  {
  	  	  	scanf("%s",ch);
  	  	  	if(c==0 && strcmp(ch,"cookie")==0)
  	  	  	  {
  	  	  	  	c=1;
  	  	  	  	continue;
			  }
			if(c==1 && strcmp(ch,"cookie")==0)
			  {
			  	ans=1;
			  }
			if(strcmp(ch,"milk")==0)
			  c=0;
	     }
	    if((j==2 || j==n+1)  && strcmp(ch,"cookie")==0)
	      ans=1;
	    
	    if(ans==1)
	      printf("NO\n");
	    else 
	      printf("YES\n");
			
	  }
  }