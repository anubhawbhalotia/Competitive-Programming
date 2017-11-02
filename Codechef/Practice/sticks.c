    #include<stdio.h>
    #include<stdlib.h>
    int main()
      {
      	int data[1001],c=0,x=0,i,j,k,n,te,t;
      	long area=1;
      	scanf("%d",&te);
      	for(i=0;i<te;i++)
      	  {
      	  	area=1,x=0;
      	  	scanf("%d",&n);
      	  	for(j=c;j<c+n;j++)
      	  	  scanf("%d",&data[j]);
      	  	for(j=c;j<c+n-1;j++)
      	  	  {
      	  	  	for(k=j+1;k<c+n;k++)
      	  	  	  {
      	  	  	  	if(data[j]<data[k])
      	  	  	  	  {
      	  	  	  	  	t=data[j];
      	  	  	  	  	data[j]=data[k];
      	  	  	  	  	data[k]=t;
      	  	  	  	  	
    			      }
    			      
    			  }
    		  }
    		for(j=c;j<c+n;j++)
    		  {
    		  	if(x==2)
    		  	  break;
    			if(data[j]==data[j+1])
    		  	  {
    		  	  	area=area*data[j];
    		  	  	j++;
    		  	  	x++;
    			  }
    		  }
    		if(x<2)
    		  printf("-1\n");
    		else
    		  printf("%ld\n",area);
    		c=c+n;
      }
    } 