    #include<bits/stdc++.h>
    using namespace std;
    long a[100009];
    long  long pre[100009],post[100009];
    long bspre(long s,long start,long end)//find index <=s
    {
    	if(start>=end)
    	{
    		if(pre[start]<=s)
    		{
    			return start;
    		}
    		else
    		{
    			return -1;
    		}
    	}
    	long mid=((start+end)/2) + 1;
    	if(pre[mid]>s)
    	{
    		return bspre(s,start,mid-1);
    	}
    	else
    	{
    		return bspre(s,mid,end);
    	}
     
    }
    long bspost(long s,long start,long end)//find index <=s
    {
    	if(start>=end)
    	{
    		if(post[start]<=s)
    		{
    			return start;
    		}
    		else
    		{
    			return -1;
    		}
    	}
    	long mid=((start+end)/2);
    	if(post[mid]<=s)
    	{
    		return bspost(s,start,mid);
    	}
    	else
    	{
    		return bspost(s,mid+1,end);
    	}
     
    }
    int main()
    {
    	long t,n,i;
    	cin>>t;
    	while(t--)
    	{
    		scanf("%ld",&n);
    		long ans[100009]={},f[100009]={},s;
    		long long temp1,temp2;
    		pre[0]=0;
    		for(i=1;i<=n;i++)
    		{
    			scanf("%ld",&a[i]);
    			pre[i]=pre[i-1]+a[i];
    		}	
    		a[n+1]=0;
    		for(i=n;i>=1;i--)
    		{
    			post[i]=post[i+1]+a[i];
    		}
    		/*for(i=1;i<=n;i++)
    		{
    			cout<<pre[i]<<" ";
    		}
    		cout<<endl;
    		for(i=1;i<=n;i++)
    		{
    			cout<<post[i]<<" ";
    		}
    		cout<<endl;
    		cout<<"bspre"<<endl;*/
    		for(i=1;i<=n-1;i++)
    		{
    			temp1=bspre(a[i]+pre[i],i+1,n);
    			if(temp1!=-1)
    			{
    				ans[temp1+2]-=1;
    				ans[i+1]+=1;
    			}
    			else
    			{
    				ans[i+1]+=1;
    				ans[i+2]-=1;
    			}
    			//cout<<temp1<<" ";
    		}
    		/*cout<<endl;
    		for(i=1;i<=n;i++)
    		{
    			printf("%ld ",ans[i]);
    		}
    		printf("\n");
    		printf("\n");*/
    		/*s=0;
    		for(i=1;i<=n;i++)
    		{
    			s=s+ans[i];
    			f[i]=s;
    		}*/
    		/*fo r(i=1;i<=n;i++)
    		{
    			printf("%ld ",f[i]);
    		}
    		printf("\n");
    		cout<<"\nbspost"<<endl;*/
    		for(i=2;i<=n;i++)
    		{
    			temp2=bspost(a[i]+post[i],1,i-1);
    			if(temp2!=-1)
    			{
    				ans[temp2-1]+=1;
    				ans[i]-=1;
    			}
    			else
    			{
    				ans[i-1]+=1;
    				ans[i]-=1;
    			}
    			//cout<<temp2<<" ";
    		}
    		//cout<<endl;
    		/*for(i=1;i<=n;i++)
    		{
    			printf("%ld ",ans[i]);
    		}
    		printf("\n");*/
    		s=0;
    		for(i=0;i<=n;i++)
    		{
    			s=s+ans[i];
    			f[i]=s;
    		}
    		for(i=1;i<=n;i++)
    		{
    			printf("%ld ",f[i]);
    		}
    		printf("\n");
    	} 
    } 