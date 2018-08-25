#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	scanf("%ld",&n);
	long a[n],b[n];
	long smax1=-1,smax2=-1,emin1=1000000001,emin2=1000000001;
	long smax1Ind=-1,smax2Ind=-1,emin1Ind=-1,emin2Ind=-1;
	long smin,emax;
	for(long i=0;i<n;i++)
	{
		scanf("%ld %ld",&a[i],&b[i]);
		if(a[i]>=smax1)
		{
			smax2=smax1;
			smax2Ind=smax1Ind;
			smax1=a[i];
			smax1Ind=i;
		}
		else if(a[i]<smax1 && a[i]>smax2)
		{
			smax2=a[i];
			smax2Ind=i;
		}
		if(b[i]<=emin1)
		{
			emin2=emin1;
			emin2Ind=emin1Ind;
			emin1=b[i];
			emin1Ind=i;
		}
		else if(b[i]>emin1 && b[i]<emin2)
		{
			emin2=b[i];
			emin2Ind=i;
		}
		// if(s[i]<smin)
		// {
		// 	smin=s[i];
		// }
		// if(s[i]>emax)
		// {
		// 	emax=s[i];
		// }
	}
	//cout<<smax1<<" "<<smax2<<" "<<emin1<<" "<<emin2<<endl;
	long ans;
	if(smax1Ind==emin1Ind)
	{
		ans=emin2- smax2 ;
	}
	else 
	{
		long temp1=smax1-smax2;
		long temp2=emin2-emin1;
		if(temp1>=temp2)
		{
			ans=emin1 - smax2;
		}
		else
		{
			ans=emin2- smax1;
		}
	}
	if(ans<0)	ans=0;
	printf("%ld\n",ans);

}