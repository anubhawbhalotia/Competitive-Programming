#include <bits/stdc++.h>
using namespace std;
int main()
{
	long i,j,k,t,n,inp,mf,cc;
	cin>>t;
	while(t--)
	{
		cc=0;
		long long a[1000000]={},b[1000000]={};
		cin>>n;
		long ts[n];
		vector <long> ni[n];
		for(i=0;i<n;i++)
		{
			cin>>ts[i];
			for(j=0;j<ts[i];j++)
			{
				cin>>inp;
				ni[i].push_back(inp);
			}
		}
		//cout<<"input\n";
		mf=n-1;
		long long temp,max=0;
		int d=0;
		long long max1=0,max2=0,min1=1000000000000000,min2=1000000000000000;
		if(n==2)
		{
			for(i=0;i<ts[0];i++)
			{
				if(ni[0][i]>max1)
				{
					max1=ni[0][i];
				}
				if(ni[0][i]<min1)
				{
					min1=ni[0][i];
				}
			}
			for(i=0;i<ts[1];i++)
			{
				if(ni[1][i]>max2)
				{
					max2=ni[1][i];
				}
				if(ni[1][i]<min2)
				{
					min2=ni[1][i];
				}
			}
			if(abs(max1-min2)>abs(min1-max2))
			{
				cout<<abs(max1-min2)<<"\n";
			}
			else
			{
				cout<<abs(max2-min1)<<"\n";
			}
		}
		else
		{
		for(i=n-2;i>=0;i--)
		{
			cc=0;
			if(d==0)
			{
				for(j=ts[i]-1;j<=((ts[i]-1)*2);j++)
				{
					max=0;
					for(k=0;k<ts[i+1];k++)
					{
						temp=((abs(ni[i][j%ts[i]]-ni[i+1][k])*mf)+a[k]);
						//cout<<temp<<" ";
						if(temp>max)
						{
							max=temp;
						}
					}
					//cout<<"\n";
					b[cc++]=max;
				}
				/*for(j=0;j<cc;j++)
				{
					cout<<b[j]<<" ";
				}
				cout<<"\n";*/
			}
			else
			{
				for(j=ts[i]-1;j<=((ts[i]-1)*2);j++)
				{
					max=0;
					for(k=0;k<ts[i+1];k++)
					{
						temp=((abs(ni[i][j%ts[i]]-ni[i+1][k])*mf)+b[k]);
						//cout<<temp<<" ";
						if(temp>max)
						{
							max=temp;
						}
					}
					a[cc++]=max;
				}
				/*for(j=0;j<cc;j++)
				{
					cout<<a[j]<<" ";
				}
				cout<<"\n";*/
			}
			d=!d;
			mf--;
			
		}

		if(d==1)
		{
			for(i=0;i<cc;i++)
			{
				//cout<<b[i]<<" ";
				if(b[i]>max)
				{
					max=b[i];
				}
			}
		}
		else
		{
			for(i=0;i<cc;i++)
			{
				//cout<<a[i]<<" ";

				if(a[i]>max)
				{
					max=a[i];
				}
			}
		}
		cout<<max<<"\n";
		}
	}
}

