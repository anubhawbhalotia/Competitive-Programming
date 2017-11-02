    #include<stdio.h>
    #include<string.h>
    int chef(char *);
    int main()
      {
        int i,a[11],t;
        char s[100000];
        scanf("%d",&t);
        fflush(stdin);
    	for(i=1;i<=t;i++)
    	  {
    	  	scanf("%s",s);
    	  	fflush(stdin);
    	  	a[i]=chef(s);
    	  }
    	for(i=1;i<=t;i++)
    	  printf("%d\n",a[i]);
      }
    int chef(char *p)
      {
      	int c=0;
    	  while(1)
    	    {
    	      if(*p=='<' && *(p+1)=='>')
    	        c++;
    	      if(*(p+1)=='\0' || *p=='\0')
    	        break;
    	      p++;
    		}
    		
    	  return c;
      } 