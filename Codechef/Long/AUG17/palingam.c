    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    int main()
    {
    	int ans,t,i,af[27],bf[27],p;
    	char a[600],b[600];
    	scanf("%d",&t);
    	while(t--)
    	{
    		char a[600],b[600];
    		scanf("%s",a);
    		fflush(stdin);
    		scanf("%s",b);
    		p=0;
    		//puts(a);
    		for(i=1;i<=26;i++)
    		{
    			af[i]=0;
    			bf[i]=0;
    		}
    		p=0;
    		//printf("Length %ld\n",strlen(a));
    		while(p<strlen(a))
    		{
    			af[(*(a+p))-96]++;
    			bf[(*(b+p))-96]++;
    			p++;
    		}
    		/*for(i=1;i<=26;i++)
    		{
    			printf("af[%d]=%d\tbf[%d]=%d\n",i,af[i],i,bf[i]);
    		}*/
    		ans=0;
    		for(i=1;i<=26;i++)
    		{
    			if(af[i]>=2 && bf[i]==0)
    			{
    				ans=1;
    				break;
    			}
    		}
    		if(ans==1)
    		{
    			printf("A\n");
    			continue;
    		}
    		ans=0;
    		for(i=1;i<=26;i++)
    		{
    			if(af[i]>=1 && bf[i]==0)
    			{
    				ans=1;
    				break;
    			}
    		}
    		if(ans==0)
    		{
    			printf("B\n");
    			continue;
    		}
    	    else
    	    {
    	    	ans=0;
    	    	for(i=1;i<=26;i++)
    	    	{
    	    		if(bf[i]>=1 && af[i]==0)
    	    		{
    	    			ans=1;
    	    			break;
    	    		}
    	    	}
    	    	if(ans==1)
    	    	{
    	    		printf("B\n");
    	    		continue;
    	    	}
    	    	else
    	    	{
    	    		printf("A\n");
    	    		continue;
    	    	}
    	    }
     
    		/*for(i=1;i<=26;i++)
    		{
    			if(af[i]==1 && bf[i]==0)
    			{
    				ans=2;
    				break;
    			}
    		}
    		if(ans==2)
    		{
    			printf("B\n");
    			continue;
    		}
    		for(i=1;i<=26;i++)
    		{
    			if(af[i]>=1 && bf[i]>=1)
    			{
    				ans=2;
    				break;
    			}
    		}
    		if(ans==2)
    		{
    			printf("B\n");
    			continue;
    		}*/
    	}
    } 