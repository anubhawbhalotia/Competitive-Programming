#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,last,la,lb,sum,m,i;
	cin>>n;
	while(n!=0)
	{
		long a[n];
		long long aa[25000]={},aaa[25000]={};		
		cin>>a[0];
		a[0]+=10000;
		aa[a[0]]=a[0];
		aaa[a[0]]=1;
		last=a[0];
		for(i=1;i<n;i++)
		{
			cin>>a[i];
			a[i]+=10000;
			aa[a[i]]=last+a[i];
			aaa[a[i]]=i+1;
			last=aa[a[i]];
		}
		cin>>m;
		long b[m];
		long long bb[25000]={},bbb[25000]={};
		cin>>b[0];
		b[0]+=10000;
		bb[b[0]]=b[0];
		bbb[b[0]]=1;
		last=b[0];
		for(i=1;i<m;i++)
		{
			cin>>b[i];
			b[i]+=10000;
			bb[b[i]]=last+b[i];
			bbb[b[i]]=i+1;
			last=bb[b[i]];
		}
		la=0;
		lb=0;
		sum=0;
		/*for(i=0;i<n;i++)
		{
			cout<<aa[a[i]]<<" ";
		}
		cout<<endl;
		for(i=0;i<m;i++)
		{
			cout<<bb[b[i]]<<" ";
		}
		cout<<endl;*/
		for(i=0;i<n;i++)
		{
			//cout<<aa[a[i]]<<" "<<bb[a[i]]<<endl;
			if(bb[a[i]]!=0)
			{
				sum=sum+max(bb[a[i]]-(10000*bbb[a[i]])-lb,aa[a[i]]-(10000*aaa[a[i]])-la);
				//cout<<"sum="<<sum<<endl;
				la=aa[a[i]]-(10000*aaa[a[i]]);
				lb=bb[a[i]]-(10000*bbb[a[i]]);
				//cout<<la<<" "<<lb<<endl;
			}

		}
		//cout<<bb[b[m-1]]<<" "<<bbb[b[m-1]<<endl;
		//cout<<bb[m-1]-(10000*bbb[m-1])-lb<<endl;
		//cout<<aa[n-1]-(10000*aaa[n-1])-la<<endl;
		sum=sum+max(bb[b[m-1]]-(10000*bbb[b[m-1]])-lb,aa[a[n-1]]-(10000*aaa[a[n-1]])-la);
		cout<<sum<<endl;
		cin>>n;
	}
}