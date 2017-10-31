#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long n,q,i,j,inp,a,b;
	long long temp1,temp2,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		vector <long int> wn[n];
		long nd[2][n];
		long nn[n],wc[n]={};
		long long sufw[n+1]={};
		for(i=0;i<n;i++)
		{
			cin>>nn[i];
			for(j=0;j<nn[i];j++)
			{
				cin>>inp;
				wn[i].push_back(inp);
			}
		}
		/*cout<<"nn[] = ";
		for(i=0;i<n;i++)
		{
			cout<<nn[i]<<" ";
		}
		cout<<"\n";*/
		sufw[0]=0;
		for(i=0;i<n;i++)
		{
			cin>>nd[1][i]>>nd[0][(i+1)%n]>>wc[i];
			sufw[i+1]=sufw[i]+wc[i];
		}
		long long suff[n+1]={},sf[n]={},lf[n]={},sufs[n+1]={},temp1,temp2;
		suff[0]=0;
		sufs[0]=0;
		for(i=0;i<n;i++)
		{
			temp1=0;
			temp2=0;
			x=nd[0][i];
			y=nd[1][i];
			if(x>y)
			{
				temp1=x;
				x=y;
				y=temp1;
			}
			a=x-y;
			if(a<0)
			{
				a=nn[i]-abs(a);
			}
			
			b=y-x;
			//cout<<"a="<<a<<" b="<<b<<"\n";
			temp1=0;
			temp2=0;
				if(a<b)
				{
					for(j=-1;j<a-1;j++)
					{
						sf[i]+=wn[i][(j+y)%nn[i]];
					}
					lf[i]=a;
				}
				else if(a>b)
				{
					for(j=x-1;j<y-1;j++)
					{
						sf[i]+=wn[i][j];
					}
					lf[i]=b;
				}
				else
				{
					for(j=-1;j<a-1;j++)
					{
						temp1+=wn[i][(j+y)%nn[i]];
					}
					for(j=x-1;j<y-1;j++)
					{
						temp2+=wn[i][j];
					}
					if(temp1<temp2)
					{
						sf[i]=temp1;
					}
					else
					{
						sf[i]=temp2;
					}
					lf[i]=a;
				}
			
			//cout<<"sf["<<i<<"]="<<sf[i]<<"\n";
			suff[i+1]=sf[i]+suff[i];
			sufs[i+1]=lf[i]+sufs[i];
		}

		/*cout<<"wn[][]\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<nn[i];j++)
			{
				cout<<wn[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"nd[]\n";
		for(i=0;i<n;i++)
		{
			cout<<nd[0][i]<<" "<<nd[1][i]<<"\n";
		}
		cout<<"sf[]\n";
		for(i=0;i<n;i++)
		{
			cout<<sf[i]<<" ";
		}
		cout<<"\nsuff[]\n";
		for(i=0;i<=n;i++)
		{
			cout<<suff[i]<<" ";
		}
		cout<<"\nlf[]\n";
		for(i=0;i<n;i++)
		{	
			cout<<lf[i]<<" ";
		}
		cout<<"\nsufs[]\n";
		for(i=0;i<=n;i++)
		{
			cout<<sufs[i]<<" ";
		}
		cout<<"\n";
		*/

		while(q--)
		{

			long v1,c1,v2,c2;
			long long d1=0,d2=0,l1,l2,w1=0,wtemp1=0,wtemp2=0,x,y;
			cin>>v1>>c1>>v2>>c2;
			if(n==1)
			{
				cout<<"0\n";
				continue;
			}
			if(c1>c2)
			{
				temp1=c1;
				c1=c2;
				c2=temp1;
				temp1=v1;
				v1=v2;
				v2=temp1;
			}
			//CALCULATING l1 and l2
			l1=0,l2=0;
			l1+=sufs[c2-1]-sufs[c1];
			l2+=sufs[n]-(l1+lf[c1-1]+lf[c2-1]);
			//cout<<"l1="<<l1<<" l2="<<l2<<"\n";
			l1+=c2-c1;
			l2+=n-(c2-c1);
			//cout<<"l1="<<l1<<" l2="<<l2<<"\n";

			//distance between v1 and nd[0][c1-1]
			d1=(v1-nd[1][c1-1]);
			if(d1<0)
			{
				d1=nn[c1-1]-abs(d1);
			}
			d2=(nd[1][c1-1]-v1);
			if(d2<0)
			{
				d2=nn[c1-1]-abs(d2);
			}
			l1+=(d1<=d2)?(d1):(d2);
			//distance between v2 and nd[1][c2-1]
			d1=(v2-nd[0][c2-1]);
			if(d1<0)
			{
				d1=nn[c2-1]-abs(d1);
			}
			d2=(nd[0][c2-1]-v2);
			if(d2<0)
			{
				d2=nn[c2-1]-abs(d2);
			}
			l1+=(d1<=d2)?(d1):(d2);
			
			d1=(v1-nd[0][c1-1]);
			if(d1<0)
			{
				d1=nn[c1-1]-abs(d1);
			}
			d2=(nd[0][c1-1]-v1);
			if(d2<0)
			{
				d2=nn[c1-1]-abs(d2);
			}
			l2+=(d1<=d2)?(d1):(d2);
			//cout<<"l1="<<l1<<" l2="<<l2<<"\n";

			d1=(v2-nd[1][c2-1]);
			if(d1<0)
			{
				d1=nn[c2-1]-abs(d1);
			}
			d2=(nd[1][c2-1]-v2);
			if(d2<0)
			{
				d2=nn[c2-1]-abs(d2);
			}

			l2+=(d1<=d2)?(d1):(d2);
			//cout<<"l1="<<l1<<" l2="<<l2<<"\n";
			if(l1<l2)
			{
				w1+=suff[c2-1]-suff[c1];
				w1+=sufw[c2-1]-sufw[c1-1];
			 	x=v1;
			 	y=nd[1][c1-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c1-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		w1+=wn[c1-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		w1+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c1-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    	w1+=(temp1<=temp2)?(temp1):(temp2);

			    }
			    x=v2;
			 	y=nd[0][c2-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c2-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		w1+=wn[c2-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		w1+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c2-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    	w1+=(temp1<=temp2)?(temp1):(temp2);

			    }
			    

			}
			else if(l1>l2)
			{
				w1+=suff[c1-1]+suff[n]-suff[c2];
				w1+=sufw[n]-(sufw[c2-1]-sufw[c1-1]);
				//cout<<"w1="<<w1<<"\n";
				x=v1;
			 	y=nd[0][c1-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c1-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		w1+=wn[c1-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		w1+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c1-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    	w1+=(temp1<=temp2)?(temp1):(temp2);

			    }

			    x=v2;
			 	y=nd[1][c2-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c2-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		w1+=wn[c2-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		w1+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c2-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    	w1+=(temp1<=temp2)?(temp1):(temp2);

			    }
			}
			//l1==l2
			else
			{
				wtemp1+=suff[c2-1]-suff[c1];
				wtemp1+=sufw[c2-1]-sufw[c1-1];
			 	x=v1;
			 	y=nd[1][c1-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c1-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		wtemp1+=wn[c1-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		wtemp1+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c1-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    	wtemp1+=(temp1<=temp2)?(temp1):(temp2);

			    }
			    x=v2;
			 	y=nd[0][c2-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c2-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		wtemp1+=wn[c2-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		wtemp1+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c2-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    	wtemp1+=(temp1<=temp2)?(temp1):(temp2);

			    }
//
			    wtemp2+=suff[c1-1]+suff[n]-suff[c2];
				wtemp2+=sufw[n]-(sufw[c2-1]-sufw[c1-1]);
				x=v2;
			 	y=nd[0][c1-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c1-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		wtemp2+=wn[c1-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		wtemp2+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c1-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c1-1][(y+i)%nn[c1-1]];
			    	}
			    	wtemp2+=(temp1<=temp2)?(temp1):(temp2);

			    }

			    x=v2;
			 	y=nd[1][c2-1];
			    if(x>y)
			    {
			    	temp1=x;
			    	x=y;
			    	y=temp1;
			    }
			    d1=y-x;
			    d2=nn[c2-1]-d1;
			    temp1=0;
			    temp2=0;
			    if(d1<d2)
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		wtemp2+=wn[c2-1][i];
			    	}
			    }
			    else if(d1>d2)
			    {
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		wtemp2+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    }
			    else
			    {
			    	for(i=x-1;i<y-1;i++)
			    	{
			    		temp1+=wn[c2-1][i];
			    	}
			    	for(i=-1;i<d2-1;i++)
			    	{
			    		temp2+=wn[c2-1][(y+i)%nn[c2-1]];
			    	}
			    	wtemp2+=(temp1<=temp2)?(temp1):(temp2);

			    }
			    w1=(wtemp1<=wtemp2)?(wtemp1):(wtemp2);
			}
			cout<<w1<<"\n";



		}

	}

}