#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[4],i,j,x,y,ans=6;
	cin>>a[1]>>a[2]>>a[3];
	for(i=1;i<=3;i++)
	{	
		for(j=1;j<=3;j++)
		{
			if(j==i)
			{
				continue;
			}
			for(x=1;x<=3;x++)
			{
				if(x==i || x==j)
				{
					continue;
				}
				int b[5005]={};
				for(y=1;y<=5000;y++)
				{
					if(b[y]==0)
					{
						break;
					}
				}
				for(;y<=5000;y+=a[1])
				{
					
						b[y]=1;
					
				}
				for(y=1;y<=5000;y++)
				{
					if(b[y]==0)
					{
						break;
					}
				}
				for(;y<=5000;y+=a[2])
				{
					b[y]=1;
					
				}
				for(y=1;y<=5000;y++)
				{
					if(b[y]==0)
					{
						break;
					}
				}
				for(;y<=5000;y+=a[3])
				{
					
						b[y]=1;

				}
				int flag=0;
				for(y=1;y<=5000;y++)
				{
					if(b[y]==0)
					{
						ans--;
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					cout<<"YES";
					return 0;
				}
				
			}
		}
		
	}
	//cout<<ans;
	
		cout<<"NO";
}