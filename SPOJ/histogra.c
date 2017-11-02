#include<stdio.h>
int main()
  {
    long t,tc,n,top,c,i;
    long long max;
    scanf("%ld",&n);
    while(n!=0)
      {
        long s[n],h[n],in[n];
        long long a[n];
        for(i=0;i<n;i++)
          scanf("%ld",&h[i]);
        top=-1;
        for(i=0;i<n;i++)
          {
            a[i]=h[i];
            c=0;
            while(top>=0 && s[top]>=h[i])
              top--;
            if(top==-1)
              c=i;
            else
              c=i-in[top]-1;
            top++;
            s[top]=h[i];
            in[top]=i;
            a[i]=a[i]+(c*h[i]);
          }
        top=-1;
        for(i=n-1;i>=0;i--)
          {
            c=0;
            while(top>=0 && s[top]>=h[i])
              top--;
            if(top==-1)
              c=n-i-1;
            else
              c=in[top]-i-1;
            top++;
            s[top]=h[i];
            in[top]=i;
            a[i]+=(c*h[i]);
          }
        max=0;
        for(i=0;i<n;i++)
          {
            if(a[i]>max)
              max=a[i];
          }
        printf("%lld\n",max);
        scanf("%ld",&n);
      }
  }