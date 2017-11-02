#include<stdio.h>
int main()
  {
    int a,n,j;
    long t,i;
    long long s;
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
      {
        s=0;
        scanf("%d",&n);
        for(j=0;j<n;j++)
          {
            scanf("%d",&a);
            s=(10*s)+a;
          }
        printf("%lld\n",s);
      }
  } 