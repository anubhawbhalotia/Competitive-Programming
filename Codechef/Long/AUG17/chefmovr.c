    #include<stdio.h>
    int main()
    {
    	int t,ans;
    	long n,d,i,j,x,k;
    	long long s,e,count;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%ld %ld",&n,&d);
    		count=0;
    		s=0;
    		long a[n],temp[n];
    		long long c[2][d];
    		for(i=0;i<d;i++)
    		{
    			c[0][i]=0;
    			c[1][i]=0;
    		}
    		for(i=0;i<n;i++)
    		{
    			scanf("%ld",&a[i]);
    			(c[0][i%d])+=a[i];
    			(c[1][i%d])++;
    			s=s+a[i];
    		}
    		if(s%n!=0)
    		{
    			printf("-1\n");
    			continue;
    		}
    		e=s/n;
    		ans=0;
    		for(i=0;i<d;i++)
    		{
    			if(((c[0][i]/c[1][i])!=e) || ((c[0][i]%e)!=0))
    			{
    				ans=-1;
    				break;
    			}
    		}
    		if(ans==-1)
    		{
    			printf("-1\n");
    			continue;
    		}
    		for(i=0;i<d;i++)
    		{
    			x=0;
    			for(j=i;j<n;j=j+d)
    			{
    				temp[x]=a[j];
    				x++;
    			}
    			for(j=0;j<x;j++)
    			{
    				if(temp[j]==e)
    					continue;
    				if(temp[j]>e)
    				{
     
    					temp[j+1]+=temp[j]-e;
    					count+=temp[j]-e;
    					temp[j]=e;
    					continue;
    				}
     
    				for(k=j+1;k<x;k++)
    				{
     
    					if(temp[k]-e>0)
    					{
    						if(temp[k]-e<e-temp[j])
    						{
    							temp[j]+=(temp[k]-e);
    							count+=((temp[k]-e)*(k-j));
    							temp[k]=e;
     
    						}
    						else
    						{
    							temp[k]=temp[k]-(e-temp[j]);
    							count+=((e-temp[j])*(k-j));
    							temp[j]=e;
    							break;
    						}
    					}
    				}
    			}
      		}
      		printf("%lld\n",count);
    	}
    } 