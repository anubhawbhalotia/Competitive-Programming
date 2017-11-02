#include<stdio.h>
int main()
  {
  	int t,tc; 
   	long long n,i,j,c,s,k;
  	scanf("%d",&t);
  	for(tc=0;tc<t;tc++)
  	  {
  	  	s=0;
		scanf("%lld",&n);
		long long a[n];
  	  	for(i=0;i<n;i++)
  	  	  scanf("%lld",&a[i]);
  	  	for(i=0;i<n;i++)
  	  	  {
  	  	  	c=0;
			for(j=i;j<n-1;j++)
  	  	  	  {
  	  	  	  	if(a[j]<=a[j+1])
  	  	  	  	  c++;
  	  	  	  	else
  	  	  	  	  break;
  	  	  	  }
  	  	  	if(c!=0)
  	  	  	  { 
			    i=i+c;
  	  	  		for(k=1;k<=c;k++)
  	  	  	  	  s=s+k;
  	  	      }
  	      }
  	    s=s+n;
  	    printf("%lld\n",s);
  	  }
  }