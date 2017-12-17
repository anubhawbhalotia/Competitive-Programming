#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		queue <int> qr,qc;
		cin>>n>>m;
		long a[n][m],p,max,ans;
		int b[n][m]={},i,j,rm,rc,tr,tc;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
			}
		}
		p=0;
		ans=0;
		while(p<(n*m))
		{
			max=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(b[i][j]==0 && a[i][j]>max)
					{
						max=a[i][j];
						tr=i;
						tc=j;
					}
				}
			}
			qr.push(tr);
			qc.push(tc);
			ans++;
			while(qr.empty()==0)
			{
				tr=qr.front();
				tc=qc.front();
				qr.pop();
				qc.pop();
				if(b[tr][tc]==1)
				{
					continue;
				}
				p++;
				b[tr][tc]=1;
				if(tr>0 && b[tr-1][tc]==0 && a[tr-1][tc]<=a[tr][tc])
				{
					qr.push(tr-1);
					qc.push(tc);
				}
				if(tc<(m-1) && b[tr][tc+1]==0 && a[tr][tc+1]<=a[tr][tc])
				{
					qr.push(tr);
					qc.push(tc+1);
				}
				if(tr<(n-1) && b[tr+1][tc]==0&& a[tr+1][tc]<=a[tr][tc])
				{
					qr.push(tr+1);
					qc.push(tc);
				}
				if(tc>0 && b[tr][tc-1]==0 && a[tr][tc-1]<=a[tr][tc])
				{
					qr.push(tr);
					qc.push(tc-1);
				}
			}
		}
		cout<<ans<<endl;

	}
}