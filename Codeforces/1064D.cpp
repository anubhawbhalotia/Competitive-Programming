#include<bits/stdc++.h>
using namespace std;
//anubhaw
int main()
{
	long n,m,r,c,x,y;
	scanf("%ld %ld",&n,&m);
	scanf("%ld %ld",&r,&c);
	long left[2001][2001]={};
	r--;
	c--;
	scanf("%ld %ld",&x,&y);
	char a[n][m];
	int b[2001][2001]={};
	for(long i=0;i<n;i++)
	{
		for(long j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	queue < pair <long,long> > q;
	queue < pair <long,long> > l;
	l.push(make_pair(x,y));
	q.push(make_pair(r,c));
	b[r][c]++;
	left[r][c]=x;
	pair < long,long> p,pp;
	int row[]={1,-1,0,0};
	int col[]={0,0,-1,1};
	long newR,newC;
	long ans=1;
	a[r][c]='+';
	while(!l.empty())
	{
		p=q.front();
		pp=l.front();
		q.pop();
		l.pop();
		long tempR=p.first;
		long tempC=p.second;
		long lX=pp.first;
		long lY=pp.second;
		for(int i=0;i<2;i++)
		{
			newR=tempR+row[i];
			newC=tempC+col[i];
			if(newR>=0 && newR<n && newC>=0 && newC<m)
			{
				if((a[newR][newC]=='.' ) || (a[newR][newC]=='+' && left[newR][newC]<lX))
				{
					q.push(make_pair(newR,newC));
					l.push(make_pair(lX,lY));
					left[newR][newC]=lX;
					if(a[newR][newC]=='.')
						ans++;
					a[newR][newC]='+';
				}
			}
		}
		newR=tempR+row[3];
		newC=tempC+col[3];
		if(newR>=0 && newR<n && newC>=0 && newC<m && lY>0)
		{
			if((a[newR][newC]=='.') ||(a[newR][newC]=='+' && left[newR][newC]<lX))
			{
				q.push(make_pair(newR,newC));
				l.push(make_pair(lX,lY-1));
				left[newR][newC]=lX;
				if(a[newR][newC]=='.')
					ans++;
				a[newR][newC]='+';
			}
		}
		newR=tempR+row[2];
		newC=tempC+col[2];
		if(newR>=0 && newR<n && newC>=0 && newC<m && lX>0)
		{
			if(( a[newR][newC]=='.' )|| (a[newR][newC]=='+' && left[newR][newC]<lX-1))
			{
				q.push(make_pair(newR,newC));
				l.push(make_pair(lX-1,lY));
				left[newR][newC]=lX-1;
				if(a[newR][newC]=='.')
					ans++;
				a[newR][newC]='+';
			}
		}
		
	}
	cout<<ans<<endl;
	// for(long i=0;i<n;i++)
	// {
	// 	for(long j=0;j<m;j++)
	// 	{
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<endl;
	// }
}