    #include<stdio.h>
    #include<math.h>
    int main()
    {
    	int t,n,v1,v2;
    	double a,b;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%d %d %d",&n,&v1,&v2);
    		a=2*n;
    		a=a/v2;
    		b=sqrt(2);
    		b=b*n;
    		b=b/v1;
    		if(a<b)
    		{
    			printf("Elevator\n");
    		}
    		else
    		{
    			printf("Stairs\n");
    		}
    	}
    } 