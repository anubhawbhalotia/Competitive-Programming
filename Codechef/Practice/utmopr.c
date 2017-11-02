#include<stdio.h>
int utmopr(long n,long long k)
  {
    long long s=0,a[1001];
    
    int i;
    for(i=0;i<n;i++)
      {
        scanf("%lld",&a[i]);
        s=s+a[i];
      }
    if(s%2==0)
      {
        if(k==1)
          return 0;
        else return 1;
      }
    else
      return 1;
  }
int main()
  {
    int t,i,n;
    long k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
      {
        scanf("%d %ld",&n,&k);
        utmopr(n,k)==1?printf("even\n"):(printf("odd\n"));
      }
    return 0;
  }