#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,qq;
	cin>>n>>qq;
	long total,x,type	;
	long f[300100]={};
	int a[300100]={};
	queue <long> q;
	long maxx=0;
	while(qq--)
	{
		cin>>type>>x;
		switch(type)
		{
			case 1:
				q.push(x);
				f[x]++;
				total++;
				cout<<total<<endl;
				break;
			case 2:
				q.push((-1)*x);
				a[x]++;
				total-=f[x];
				f[x]=0;
				cout<<total<<endl;
				break;
			case 3:
				if(x>maxx)
				{
					long temp=x;
					x-=maxx;
					maxx=temp;
					
				}
				else
				{
					x=0;
				}

				while(x)
				{
					if(q.front()>0)
					{
						if(a[q.front()]>0)
						{
							//a[q.front()]=0;
							q.pop();
							x--;
							continue;
						}
						f[q.front()]--;
						q.pop();
						total--;
						x--;
					}
					else
					{
						a[(-1)*q.front()]--;
						q.pop();
					}
				}
				cout<<total<<endl;


		}
	}
}