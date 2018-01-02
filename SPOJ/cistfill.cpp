#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9 +7;
typedef struct cistern
{
	long h;
	long wd;
	long long pre;

}cis;
int compare (const void * a, const void * b)
{
	cis *A=(cis*)a;
	cis *B=(cis*)b;
    return (A->h - B->h );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cis a[100000];
		long n,i,b,h,w,d,v,sum;
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld %ld %ld",&b,&h,&w,&d);
			a[i*2].h=b;
			a[i*2+1].h=b+h;
			a[i*2].wd=w*d;
			a[i*2+1].wd=(-1)*w*d;
		}
		scanf("%ld",&v);
		qsort(a,n*2,sizeof(cis),compare);
		/*for(i=0;i<2*n;i++)
		{
			cout<<a[i].h<<" "<<a[i].wd<<endl;
		}*/
		sum=a[0].wd;
		a[0].pre=0;
		for(i=1;i<2*n;i++)
		{
			a[i].pre=a[i-1].pre+(sum*(a[i].h-a[i-1].h));
			//cout<<a[i].pre<<endl;
			if(a[i].pre>=v)
			{
				printf("%.2lf\n",a[i-1].h+((double)(v-a[i-1].pre))/(double)sum);
				break;
			}
			sum+=a[i].wd;
		}	
		if(i==2*n)
		{
			printf("OVERFLOW\n");
		}
	}
}

		