    #include<stdio.h>
    #include<stdlib.h>
    int cmpf (const void * a, const void * b)
    {
       return (*(long  *)a-(*(long  *)b));
    }
    int main()
    {
    	long n,i,x;
    	int t,tc;
    	long long a=0;
    	scanf("%d",&t);
    	for(tc=0;tc<t;tc++)
    	{
    		a=0;
    		scanf("%ld",&n);
    		for(i=0;i<n;i++)
    		{
    			scanf("%ld",&x);
    			a=a|x;
    		}
    		printf("%lld\n",a);
    		
    	    
    	}
    } 