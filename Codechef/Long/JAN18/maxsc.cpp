    #include<bits/stdc++.h>
    using namespace std;
    const long long mod=1e9 +7;
    long a[700][700];
    long long b[700][700];
    int n;
    int compare (const void * a, const void * b)
    {
      return ( *(long*)a - *(long*)b );
    }
    void display()
    {
    	int i,j;
    	cout<<endl;
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			cout<<a[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	cout<<endl;
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    		{
    			cout<<b[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    }
    int main()
    {
    	int t,x;
    	long i,j;
    	long long max;
    	scanf("%d",&t);
    	while(t--)
    	{
    		scanf("%d",&n);
    		for(i=0;i<n;i++)
    		{
    			for(j=0;j<n;j++)
    			{
    				scanf("%ld",&a[i][j]);
    			}
    			qsort(a[i],n,sizeof(long),compare);
    		}
    		max=-10;
    		for(i=n-1;i>=0;i--)
    		{
    			if(a[n-1][i]>max)
    			{
    				max=a[n-1][i];
    			}
    			b[n-1][i]=max;
    		}
    		for(i=n-2;i>=0;i--)
    		{
    			max=-10;
    			x=n-1;
    			for(j=n-1;j>=0;j--)
    			{
    				while(a[i+1][x]>a[i][j] && x>=0)
    				{
    					x--;
    				}
    				x++;
    				if(x==n)
    				{
    					x=n-1;
    					b[i][j]=-1;
    					continue;
    				}
    				if(b[i+1][x]==-1)
    				{
    					b[i][j]=-1;
    					continue;
    				}
    				if((a[i][j]+b[i+1][x])>max)
    				{
    					max=a[i][j]+b[i+1][x];
    				}
    				b[i][j]=max;
    			}
    		}
    		max=-10;
    		for(i=0;i<n;i++)
    		{
    			if(b[0][i]>max)
    			{
    				max=b[0][i];
    			}
    		}
    		//display();
    		printf("%lld\n",max);
    		
    	}
    }
     
    		 


