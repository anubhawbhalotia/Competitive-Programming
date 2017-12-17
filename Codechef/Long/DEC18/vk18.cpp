    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    	long n,i,s,t,e,m=1000001,nn;
    	int x,ee,o;
    	long f[2*(m+1)];
    	long long h[m+1],g[2*(m+1)];
    	g[0]=0;
    	for(i=1;i<=m*2;i++)
    	{
    		n=i;
    		ee=0;
    		o=0;
    		while(n!=0)
    		{
    			x=n%10;
    			if(x%2==0)
    			{
    				ee+=x;
    			}
    			else
    			{
    				o+=x;
    			}
    			n=n/10;
    		}
    		f[i]=abs(ee-o);
    		g[i]=g[i-1]+f[i];
    	}
    	s=3;
    	e=4;
    	h[1]=2;
    	for(i=2;i<=m;i++)
    	{
    		h[i]=h[i-1]+(g[e]-g[s-1])*2-f[e];
    		e+=2;
    		s++;
    	}
    	cin>>t;
    	while(t--)
    	{
    		cin>>nn;
    		cout<<h[nn]<<endl;
    	}
    	
    	/*for(i=0;i<m;i++)
    	{
    		cout<<f[i]<<" ";
    	}
    	cout<<endl;
    	for(i=0;i<m;i++)
    	{
    		cout<<g[i]<<" ";
    	}
    	cout<<endl;
    	for(i=0;i<m;i++)
    	{
    		cout<<h[i]<<" ";
    	}
    	cout<<endl;*/
    } 