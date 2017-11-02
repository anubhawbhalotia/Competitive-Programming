#include<stdio.h>
int main()
  {
  	int t,tc;
  	long long a[10000],n,i,c[10000],x,d;
  	scanf("%d",&t);
  	for(tc=1;tc<=t;tc++)
  	  {
  	  	d=0;
		scanf("%lld",&n);
  	  	scanf("%lld",&a[0]);
  	  	c[0]=a[0];
		for(i=1;i<n;i++)
		  {
		    scanf("%lld",&a[i]);
		    c[i]=a[i]-a[i-1];
		  }
		for(i=0;i<n;i++)
		  {
		  	scanf("%lld",&x);
		  	if(x<=c[i])
		  	  d++;
		  }
		printf("%d\n",d);
      }
}