    #include<stdio.h>
    #include<stdlib.h>
    int main()
      {
      	int i,n,c;
      	char s[30],ch[30],*j,*k;
      	fflush(stdin);
      	scanf("%s",s);
      	fflush(stdin);
      	scanf("%d",&n);
      	fflush(stdin);
      	for(i=0;i<n;i++)
      	  {
      	  	scanf("%s",ch);
      	  	fflush(stdin);
      	  	j=ch;
      	  	while(*j!='\0')
      	  	  {
      	  	  	k=s;
      	  	  	c=0;
    			while(*k!='\0')
      	  	  	  {
      	  	  	  	if(*j==*k)
      	  	  	  	  {
      	  	  	  	  	c=1;
      	  	  	  	  	break;
    				  }
    				k++;
    			  }
    			if(c==0)break;
    			j++;
    		  }
    		if(c==1)
    		  printf("Yes\n");
    		else
    		  printf("No\n");
    		}
      } 