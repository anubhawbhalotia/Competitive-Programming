    #include<stdio.h>
    #include<math.h>
    int main()
    {
    	long long c=0;
    	long a,b,x,i,j;
    	scanf("%ld %ld",&a,&b);
    	x=floor(sqrt((a*a)+b));
    	for(i=x;i>=1;i--)
    	{
    		for(j=i-1;j>=1;j--)
    		{
    			if(j<=a)
    			{
    				if(((i*i)-(j*j))<=b && ((i*i)-(j*j))>0)
    				{
    					//printf("%ld %ld\n",j,(i*i)-(j*j));
    					c++;
    				}
    				else
    					if(((i*i)-(j*j))>b)
    						break;
    			}
    		}
    	}
    	printf("%lld",c);
     
    } 