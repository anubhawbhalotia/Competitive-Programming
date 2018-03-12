    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    	int c;
    	long n,q,i,no,nn,l,r,j;
    	long long x,ans;
    	cin>>n>>q;
    	long a[n+1];
    	int b[31][n+1];
    	for(i=1;i<=n;i++)
    	{
    		cin>>a[i];
    	}
    	x=1;
    	for(i=1;i<=30;i++)
    	{
    		x=x*2;
    	}
    	/*for(i=1;i<=n;i++)
    	{
    		cout<<a[i]<<" ";
    	}
    	cout<<endl;*/
    	c=0;
    	int s=0;
    	while(1)
    	{
    		b[c][0]=0;
    		for(i=1;i<=n;i++)
    		{
    			if(a[i]&x)
    			{
    				//cout<<"yes "<<(a[i]&x)<<endl;
    				b[c][i]=b[c][i-1]+1;
    			}
    			else
    			{
    				//cout<<"no "<<(a[i]&x)<<endl;
    				b[c][i]=b[c][i-1];
    			}
    		}
    		c++;
    		x/=2;
    		if(x==0)
    		{
    			s++;
    		}
    		if(s==2)
    		{
    			break;
    		}
    	}
     
    	/*for(i=0;i<31;i++)
    	{
    		for(j=1;j<=n;j++)
    		{
    			cout<<b[i][j]<<" ";
    		}
    		cout<<endl;
    	}*/
    	while(q--)
    	{
    		cin>>l>>r;
    		ans=0;
    		for(i=0;i<31;i++)
    		{
    			no=b[i][r]-b[i][l-1];
    			nn=r-l+1;
    			ans=ans<<1;
    			//cout<<no<<" "<<nn<<" ";
    			if(nn%2==0 && no*2==nn)
    			{
    				ans+=0;
    			}
    			else if(no>nn/2)
    			{
    				ans+=0;
    			}
    			else
    			{
    				ans+=1;
    			}
    			//cout<<ans<<endl;
    		}
    		cout<<ans<<endl;
    	}
    } 