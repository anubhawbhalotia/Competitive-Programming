#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,i,j,d,l;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long a[n],b[n],c[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			c[i]=0;
		}
		d=0;
		for(i=0;i<n-1;i++)
		{
			if(c[i]==0)
			{
				for(j=i+1;j<n;j++)
				{
					if(a[i]!=a[j] && c[j]==0)
					{
						//cout<<"i not equal to j\n";
						b[j]=a[i];
						b[i]=a[j];
						c[i]=1;
						c[j]=1;
						d+=2;
						/*for(l=0;l<n;l++)
						{
							cout<<b[l]<<" ";
						}
						cout<<endl;
						for(l=0;l<n;l++)
						{
							cout<<c[l]<<" ";
						}
						cout<<endl;*/
						break;
					}					
				}
			}
		}
		for(i=0;i<n && d<n;i++)
		{
			if(c[i]==0)
			{
				for(j=0;j<n;j++)
				{
					if(c[j]==1 && a[j]!=a[i] && a[i]!=b[j])
					{
						b[i]=b[j];
						b[j]=a[i];
						c[i]=2;
						c[j]=2;
						d++;
						break;
					}
				}

			}
			if(c[i]==0)
			{
				b[i]=a[i];
				c[i]=1;
			}
		}
		if(d==n)
		{
			cout<<n<<endl;
		}
		else
		{
			cout<<d<<endl;
		}
		for(i=0;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}