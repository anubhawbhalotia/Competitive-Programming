#include<bits/stdc++.h>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(long long*)a - *(long long*)b );
}

int main()
{
	long long n,c=0,i,s=0;
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	qsort(a,n,sizeof(long long),compare);
	/*for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	s+=a[0];
	c++;
	for(i=1;i<n;i++)
	{
		if(a[i]>=s)
		{
			s+=a[i];
			c++;
		}
	}
	cout<<c;
}