    #include<stdio.h>
    int main()
      {
      	int q,t,c;
      	long long a,b;
      	scanf("%d",&t);
      	for(q=0;q<t;q++)
      	  {
      	  	scanf("%lld",&a);
      	  	scanf("%lld",&b);
      	  	c=0;
      	  	if(a-b==2 || b-a==2)
      	  	  c=1;
      	  	else
      	  	  if((a%2==0 && b==a-1) || (b%2==0 && a==b-1))
      	  	    c=1;
      	  	if(c==1)
      	  	  printf("YES\n");
      	  	else
      	  	  printf("NO\n");
      	  	    
    		}
      } 