    #include<stdio.h>
    #include<stdlib.h>
    int quicksort(long*,int,int,int);
    int partition(long*,int,int,int);
    void swap(long*,long*);
    int quicksort(long *b,int low,int high,int x)
      {
        int pi;
        if (low < high)
          {
            pi = partition(b, low, high,x);
            quicksort(b,low, pi - 1,x); 
            quicksort(b, pi + 1, high,x);
          }
      } 
    int partition(long *b,int low,int high,int x)
      {
        int i,pivot,j;
        pivot=*(b+(x*0)+high);  
        i=low - 1;
        for(j=low;j<=high-1;j++)
        {
          if(*(b+(x*0)+j)>=pivot)
            {
              i++; 
              swap((b+(x*0)+i),(b+(x*0)+j));
              swap((b+(x*1)+i),(b+(x*1)+j));
            }        
        }
        swap((b+(x*0)+i+1),(b+(x*0)+ high));
        swap((b+(x*1)+i+1),(b+(x*1)+ high));
        return(i + 1);  
      }        
    void swap(long *a,long *b)
      {
        long t;
        t=*a;  
        *a=*b;  
        *b=t;
      }
    int main()
    {
    	long long tot;
    	int t,n,m,c,nj,i,j;
    	scanf("%d",&t);
    	while(t--)
    	{
    		c=0;
    		tot=0;
    		nj=0;
    		scanf("%d %d",&n,&m);
    		long minsal[n+1],offsal[2][m+1],mxjob[m+1];
    		char qual[n+1][m+2];
    		int comid[m+1];
    		for(i=1;i<=n;i++)
    		{
    			scanf("%ld",&minsal[i]);
    		}
    		for(i=1;i<=m;i++)
    		{
    			comid[i]=0;
    			scanf("%ld",&offsal[0][i]);
    			offsal[1][i]=i;
    			scanf("%ld",&mxjob[i]);
    		}
     
    		quicksort(offsal[0],1,m,m+1);
    		/*printf("\n\n");
    		for(i=1;i<=m;i++)
    		{
    			printf("%ld %ld\n",offsal[0][i],offsal[1][i]);
    		}*/
    		for(i=1;i<=n;i++)
    		{
    			scanf("%s",qual[i]);
    			fflush(stdin);
    			for(j=1;j<=m;j++)
    			{
    				//puts(qual[i]);
    				//printf("qual[%d][%ld] = %c\n",i,offsal[1][j]-1,qual[i][offsal[1][j]-1]);
    				if((qual[i][offsal[1][j]-1]=='1') && (mxjob[offsal[1][j]])>0 && offsal[0][j]>=minsal[i])
    				{
    					c++;
    					tot=tot+offsal[0][j];
    					comid[offsal[1][j]]=1;
    					(mxjob[offsal[1][j]])--;
    					break;
    				}
    			}
    		}
    		for(i=1;i<=m;i++)
    		{
    			if(comid[i]==0)
    				nj++;
    		}
    		printf("%d %lld %d\n",c,tot,nj);
     
    	}
    } 