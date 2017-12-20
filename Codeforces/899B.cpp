#include<bits/stdc++.h>
using namespace std;
int main()
{
	int y[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int a1[]={0,2,4,6,7,9,11};
	int a2[]={3,5,8,10};
	int occ[2];
	int n,i,j,x,k,z,l;
	cin>>n;
	int a[24];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[0]==31 || a[0]==28 || a[0]==29)
	{
		x=0;
		k=0;
		if(a[0]==28 || a[0]==29)
		{
			occ[x]=a[0];
			x++;
			k=1;

		}
		l=x;
		for(i=0;i<7;i++)
		{
			x=l;
			z=a1[i];
			for(j=k;j<n;j++)
			{
				if(a[j]!=y[z%12] && a[j]!=28 && a[j]!=29)
				{
					break;
				}
				if(a[j]==28 || a[j]==29)
				{
					//cout<<"TRUE"<<endl;
					if(y[z%12]==28)
					{
						//cout<<"HAA"<<endl;
						occ[x]=a[j];
						x++;
					}
					else
					{
						break;
					}
				}
			//	cout<<i<<" "<<a[j]<<endl;
				z++;
			}
			if(j==n)
			{
				//cout<<"i="<<i<<endl;
				break;
			}

		}
		if(i<7)
		{
			if(x==1 || x==0)
			{
				cout<<"YES";
			}
			else
			{
				if(occ[0]==29 && occ[1]==29)
				{
					cout<<"NO";
				}
				else
				{
					cout<<"YES";
				}
			}
		}
		else
		{
			cout<<"NO";
		}
	}
	else  
		if(a[0]==30)
		{
			for(i=0;i<4;i++)
			{
				x=0;
				z=a2[i];
				for(j=0;j<n;j++)
				{
					if(a[j]!=y[z%12] && a[j]!=28 && a[j]!=29)
					{
						break;
					}
					if((a[j]==28 || a[j]==29))
					{
						if(y[z%12]==28)
						{
							occ[x]=a[j];
							x++;
						}
						else
						{
							break;
						}
					}
					z++;
				}
				if(j==n)
				{
					break;
				}
			}
			if(i<4)
			{
				if(x==1 || x==0)
				{
					cout<<"YES";
				}
				else
				{
					if(occ[0]==29 && occ[1]==29)
					{
						cout<<"NO";
					}
					else
					{
						cout<<"YES";
					}
				}
			}
			else
			{
				cout<<"NO";
			}
		}
}
