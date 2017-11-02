    #include<iostream>
    using namespace std;
    int dice(int d[][7],int b[],int e[],int l)
    {
    	int i,j,r;
    	while(b[l]>0 && l<=6)
    	{
    		l++;
    	}
    	if(l>6)
    	{
    		return 1;
    	}
    	for(i=1;i<=6;i++)
    	{
    		if(d[l][i]==1 || b[l]>0 || b[i]>0)
    		{
    			//cout<<"continue\n";
    			continue;
    		}
    		b[l]=i;
    		b[i]=l;
    		/*for(j=1;j<7;j++)
    		{
    			cout<<b[j]<<" ";
    		}
    		cout<<"   l="<<l<<"\n";*/
    		r=dice(d,b,e,l+1);
    		if(r==1)
    		{
    			return 1;
    		}
    		b[l]=0;
    		b[i]=0;
    		/*for(j=1;j<7;j++)
    		{
    			cout<<b[j]<<" ";
    		}
    		cout<<"   l="<<l<<"\n";*/
     
    	}	
    	return 0;
     
    }
    int main()
    {
    	int t,n,i,c,r,j;
    	cin>>t;
    	while(t--)
    	{
    		int d[7][7]={};
    		cin>>n;
    		int a[n];
    		for(i=0;i<n;i++)
    		{
    			cin>>a[i];
    		}
    		c=0;
    		for(i=1;i<7;i++)
    		{
    			d[i][i]=1;
    		}
    		for(i=0;i<n-1;i++)
    		{
    			if(a[i]==a[i+1])
    			{
    				c=1;
    				continue;
    			}
    			d[a[i]][a[i+1]]=1;
    			d[a[i+1]][a[i]]=1;
    		}
    		/*for(i=1;i<7;i++)
    		{
    			for(j=1;j<7;j++)
    			{
    				cout<<d[i][j]<<" ";
    			}
    			cout<<"\n";
    		}*/
    		if(c==1)
    		{
    			cout<<"-1\n";
    			continue;
    		}
    		int b[7]={},e[7]={};
    		r=dice(d,b,e,1);
    		if(r==1)
    		{
    			for(i=1;i<7;i++)
    			{
    				cout<<b[i]<<" ";
    			}
    			cout<<"\n";
    		}
    		else
    		{
    			cout<<"-1\n";
    		}
    	}
    } 