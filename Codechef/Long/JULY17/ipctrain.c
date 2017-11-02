#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
  long s;
  long t;
  struct element *next;
}box;
//long quicksort(long *,long ,long ,long *,long *);
//long partition(long *,long ,long ,long *,long *);
void extract_maximum (long *,long long *,long*, long long * ,long *);
void max_heapify (long *,long long *,long *,long long *,long ,long );
//void swap(long *,long *);
void insert_value (long *,long long *,long *,long long*,long ,long ,long *);
void increase_value (long *, long long * ,long*,long long*,long , long );
void solve(long long *,long *,long *,long long *,long ,long,long * );
//long find(long *,long ,long ,long *);
/*
long quicksort(long *d,long low,long high,long *t,long *s)
  {
    long pi;
    if (low < high)
      {
        pi = partition(d, low, high,t,s);
        quicksort(d,low, pi - 1,t,s); 
        quicksort(d, pi + 1, high,t,s);
      }
  } 
long partition(long *d,long low,long high,long *t,long *s)
  {
    long i,pivot,j,temp;
    pivot=*(d+high);  
    i=low - 1;
    for(j=low;j<=high-1;j++)
    {
      if(*(d+j)<=pivot)
        {
          i++; 
          temp=*(d+i);
          *(d+i)=*(d+j);
          *(d+j)=temp;
          temp=*(t+i);
          *(t+i)=*(t+j);
          *(t+j)=temp;
          temp=*(s+i);
          *(s+i)=*(s+j);
          *(s+j)=temp;
          /*swap((d+i),(d+j));
          swap((t+i),(t+j));
          swap((s+i),(s+j));
        }
    }
    temp=*(d+i+1);
    *(d+i+1)=*(d+high);
    *(d+high)=temp;
    temp=*(t+i+1);
    *(t+i+1)=*(t+high);
    *(t+high)=temp;
    temp=*(s+i+1);
    *(s+i+1)=*(s+high);
    *(s+high)=temp;
    /*swap((d+i)+1,(d+high));
    swap((t+i)+1,(t+high));
    swap((s+i)+1,(s+high));
    return(i + 1);  
  }    
  */
void extract_maximum (long *arr,long long *sad,long *sadind,long long *freq,long *length)
  {
    if(*length == 0)
      return ;
    if(*(freq+1)==1)
      {
        long max = *(arr+1);
        *(arr+1) = *(arr+(*length));
        *(freq+1) = *(freq+(*length));
        *(arr+(*length))=0;
        *(freq+(*length))=0;
        *(sad+max)=0;
 
        *length = *length -1;
        max_heapify(arr,sad,sadind,freq, 1,*length);
        return ;
      }
    else
      {
        *(freq+1)=*(freq+1) - 1;
        *(sad+*(arr+1))-=1;
      }
  }
              
void max_heapify (long *arr,long long *sad,long *sadind,long long *freq,long i,long n)
  {
    long left  = 2*i;
    long right = 2*i+1;
    long largest;
    long long temp;
    if((left <= n) && (*(arr+left) > *(arr+i)))
      largest = left;
    else
      largest = i;
    if(right <= n && *(arr+right) > *(arr+largest))
      largest = right;
    if(largest != i) 
      {
        //swap((arr+i), (arr+largest));
        temp=*(arr+i);
        *(arr+i)=*(arr+largest);
        *(arr+largest)=temp; 
        *(sadind+*(arr+i))=i;
        *(sadind+*(arr+largest))=largest;
        //swap((freq+i),(freq+largest));
        temp=*(freq+i);
        *(freq+i)=*(freq+largest);
        *(freq+largest)=temp;
        max_heapify(arr,sad,sadind,freq,largest,n);
      } 
  }
/*void swap(long *a,long *b)
  {
    long temp;
    temp=*a;
    *a=*b;
    *b=temp;
  }
*/
  
void insert_value (long *arr,long long *sad,long *sadind,long long *freq,long val,long t,long *length)
  {
   // printf("Inside Insert Value\n");
    
    *length = *length + 1;
    *(arr+(*length)) = val;  
    *(freq+(*length))=t;
    *(sad+val)=t;
    *(sadind+val)=*length;
    increase_value(arr,sad,sadind,freq,*length,val);
    
  }
void increase_value (long *arr, long long *sad,long *sadind,long long *freq,long i, long val)
  {
   // printf("Inside INcrease Value\n");
    long long temp;
    while( i > 1 && *(arr+(i/2))  < *(arr+i))
    {
        //swap((arr+i/2), (arr+i));
        temp=*(arr+i/2);
        *(arr+i/2)=*(arr+i);
        *(arr+i)=temp;
        *(sadind+*(arr+i/2))=i/2;
        *(sadind+*(arr+i))=i; 
        //swap((freq+(i/2)),(freq+i));
        temp=*(freq+i/2);
        *(freq+i/2)=*(freq+i);
        *(freq+i)=temp;
        i = i/2;
    }
    
  }
  
void solve(long long *sad,long *sadind,long *arr,long long *freq,long t,long s,long *length)
  {
    
   // printf("Inside solve(c=%ld)\n",c);
        if(((*(sad+s)))!=0)
        {
 
          (*(freq+*(sadind+s)))+=t;
          *(sad+s)+=t;
        }
        //in=find(arr,1,*(s+c),length);
        //printf("in=%ld\n",in);
        //if(in!=-1)
        //  *(freq+in)+=*(t+c);
        else
          insert_value(arr,sad,sadind,freq,s,t,length);
      
  }
      
/*long find(long *arr,long z,long val,long *length)
  {
    long in;
  //  printf("Inside find\n");
    if(z<=*length && *(arr+z) == val)
      return z;
    if(*(arr+z)<val || z>*length)
      return -1;
    in=find(arr,z*2,val,length);
    if(in!=-1)
      return in;
    in=find(arr,(z*2)+1,val,length);  
    if(in!=-1)
      return in;
  }
 */    
    
int main()
  {
    int tt,tc;
    long length,n,xx,yy,c,i,j,dd;
    long long sum,x;
    //long sad[100001]={};
    //long sadind[100001];
    scanf("%d",&tt);
    for(tc=0;tc<tt;tc++)
      {
        long long sad[100001]={};
        box *a[100001]={},*temp,*z;
        long sadind[100001];
        scanf("%ld %ld",&n,&dd);
        long d[n],t[n],s[n],arr[n+2];
        long long freq[n+2];
        
        for(i=0;i<n;i++)
          {
            scanf("%ld %ld %ld",&d[i],&t[i],&s[i]);
            temp=*(a+d[i]);
            (*(a+d[i]))=(box*)malloc(sizeof(box));
            (*(a+d[i]))->s=s[i];
            (*(a+d[i]))->t=t[i];
            (*(a+d[i]))->next=temp;
            arr[i]=0;
            freq[i]=0;
          }
        arr[n]=0;
        freq[n]=0;
        arr[n+1]=0;
        freq[n+1]=0;
        //for(i=0;i<n;i++)
          //printf("d[%ld]=%ld t[%ld]=%ld s[%ld]=%ld\n",i,d[i],i,t[i],i,s[i]);
        //quicksort(d,0,n-1,t,s); 
        //for(i=0;i<n;i++)
          //printf("d[%ld]=%ld t[%ld]=%ld s[%ld]=%ld\n",i,d[i],i,t[i],i,s[i]);
        c=0;
        sum=0;
        length=0;
        for(j=1;j<=dd;j++)
          {
            //printf("arr  freq\n");
            z=*(a+j);
            while(z!=NULL)
            {
 
              solve(sad,sadind,arr,freq,z->t,z->s,&length);
              z=z->next;
            }
            
            //for(i=0;i<=length;i++)
             // printf("%ld  %ld\n",arr[i],freq[i]);
            extract_maximum (arr,sad,sadind,freq,&length);
            //printf("\n");
           // for(i=0;i<=length;i++)
            //  printf("%ld  %ld\n",arr[i],freq[i]);
           // printf("\n");
            
          }
                 
        
        for(i=1;i<=length;i++)
          {
            sum=sum+((*(freq+i)) *(*(arr+i)));
          }
        printf("%lld\n",sum);
      }
  }
         