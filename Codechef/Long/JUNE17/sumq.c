#include<stdio.h>
#include<stdlib.h>
int cmpf (const void * a, const void * b)
{
   return (*(long long *)a-(*(long long *)b));
}
long long binarys(long long q,long long *a,long long first,long long last)
  {
  
    if(last<first)
      return last;
    if(q>*(a+((first+last)/2)))
      {
        return binarys(q,a,((first+last)/2)+1,last);
      }
    if(q<*(a+((first+last)/2)))
      {
        return binarys(q,a,first,((first+last)/2)-1);
      }
   
    if(q==*(a+((first+last)/2)))
      return((first+last)/2);
  }
int main()
  {
    int t,tc;
    long long p,q,r,i,j,k,s1,s2,ind;
    long long s;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++)
      {
        s=0;
        scanf("%lld %lld %lld",&p,&q,&r);
        long long x[p],y[q],z[r];
        for(i=0;i<p;i++)
          scanf("%lld",&x[i]);
        for(i=0;i<q;i++)
          scanf("%lld",&y[i]);
        for(i=0;i<r;i++)
          scanf("%lld",&z[i]);
        qsort(x,p,sizeof(long long),cmpf);
        qsort(y,q,sizeof(long long),cmpf);
        qsort(z,r,sizeof(long long),cmpf);
        
        /*printf("\n");
        for(i=0;i<p;i++)
          printf("%lld ",x[i]);
        printf("\n");
       for(i=0;i<q;i++)
          printf("%lld ",y[i]);
        printf("\n");
       for(i=0;i<r;i++)
          printf("%lld ",z[i]);
       printf("\n");  */
       long long sx[p],sz[r];
       sx[0]=x[0];  
       for(i=1;i<p;i++)
         sx[i]=(sx[i-1]+x[i]);
       sz[0]=z[0];  
       for(i=1;i<r;i++)
         sz[i]=(sz[i-1]+z[i]);
       for(i=0;i<q;i++)
         {
           if(y[i]<x[0] || y[i]<z[0])
             {
               s=s+0;
               continue;
             }
           if(y[i]==y[i-1] && i!=0)
             {
               s=(s+((s1%1000000007)*(s2%1000000007))%1000000007)%1000000007;
               continue;
             }      
             
             
               ind=binarys(y[i],x,0,p-1);
               while(x[ind]==x[ind+1] && ind!=p-1)
                 ind++;
               s1=sx[ind]+((ind+1)*y[i]);
         
               ind=binarys(y[i],z,0,r-1);
               while(z[ind]==z[ind+1] && ind!=r-1)
                 ind++;
               s2=sz[ind]+((ind+1)*y[i]);
               s=(s+((s1%1000000007)*(s2%1000000007))%1000000007)%1000000007;
             
           
         }
       printf("%lld\n",s);
     }
 }