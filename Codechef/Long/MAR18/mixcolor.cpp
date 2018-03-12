    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    	long t,c,n,i;
    	cin>>t;
    	while(t--)
    	{
    		c=0;
    		cin>>n;
    		long a[n];
    		for(i=0;i<n;i++)
    		{
    			cin>>a[i];
    		}
    		sort(a,a+n);
    		for(i=0;i<n-1;i++)
    		{
    			if(a[i]==a[i+1])
    			{
    				c++;
    			}
    		}
    		cout<<c<<endl;
    	}
    } 