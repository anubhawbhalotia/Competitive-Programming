#include <bits/stdc++.h>
using namespace std;

struct link
{
	int s;
	long r,min,max,time;
	string israted,color;

};
int main()
{
	int n,i,j,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector <struct link> a;
		struct link temp;
		for(i=0;i<n;i++)
		{
			temp.s=0;
			cin>>temp.r>>temp.min>>temp.max>>temp.time>>temp.israted>>temp.color;
			a.push_back(temp);
		}
		cout<<"wait"<<endl;
		for(i=1;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j].s==0 && a[j].time==a[i].time && a[j].israted==a[i].israted && a[j].r>=a[i].min && a[j].r<=a[i].max && a[i].r>=a[j].min && a[i].r<=a[j].max)
				{
					if((a[j].color=="random" && a[i].color!="random") || (a[j].color!="random" && a[i].color=="random"))
					{
						continue;
					}
					if((a[j].color=="white" && a[i].color=="white") || (a[j].color=="black" && a[i].color=="black"))
					{
						continue;
					}
					a[i].s=j+1;
					a[j].s=(-1);
					break;
				}
			}
			if(a[i].s==0)
			{
				cout<<"wait"<<endl;
			}
			else
			{
				cout<<a[i].s<<endl;
			}
		}
	}
}