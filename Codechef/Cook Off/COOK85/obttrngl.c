    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
    	long k,a,b,x,x2;
    	int t;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%ld %ld %ld",&k,&a,&b);
    		x=abs(a-b)-1;
    		if(k%2==0)
    		{
    			if((x+1)==k/2)
    			{
    				printf("0\n");
    				continue;
    			}
    		}
    		x2=k-2-x;
    		if(x<x2)
    		{
    			printf("%ld\n",x);
    		}
    		else
    		{
    			printf("%ld\n",x2);
    		}
    		
     
    	}
    } 