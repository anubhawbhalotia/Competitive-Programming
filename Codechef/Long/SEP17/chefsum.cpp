    #include<stdio.h>
    int main()
    {
    	int t;
    	long n,i,mini;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%ld",&n);
    		long a[n],b[n],c[n];
    		long long min;
    		scanf("%ld",&a[0]);
    		b[0]=a[0];
    		for(i=1;i<n;i++)
    		{
    			scanf("%ld",&a[i]);
    			b[i]=b[i-1]+a[i];
    		}
    		c[n-1]=a[n-1];
    		min=c[n-1]+b[n-1];
    		mini=n-1;
    		for(i=n-2;i>=0;i--)
    		{
    			c[i]=c[i+1]+a[i];
    			if((c[i]+b[i])<=min)
    			{
    				min=c[i]+b[i];
    				mini=i;
    			}
    		}
    		/*for(i=0;i<n;i++)
    		{
    			printf("%ld %ld\n",b[i],c[i]);
    		}*/
    		printf("%ld\n",mini+1);
     
    	}
    } 