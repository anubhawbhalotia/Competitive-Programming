    #include<stdio.h>
    int main()
      {
      	int m,f,t,i,e;
      	long long j,n,s;
      	scanf("%d",&t);
      	for(i=0;i<t;i++)
      	  {
      	  	scanf("%lld",&n);
      	  	s=0;
      	  	f=0;
      	  	e=0;
      	  	for(j=0;j<n;j++)
      	  	  {
      	  	  	scanf("%d",&m);
      	  	  	if(m==2)
      	  	  	  f=1;
      	  	  	if(m==5)
      	  	  	  e=1;
      	  	  	s=s+m;
      	  	  	
    		  }
    		if(s/n<4)
    		  f=1;
    		if(f==0 && e==1)
    		  printf("Yes\n");
    		else
    		  printf("No\n");
    		}
    		
      } 