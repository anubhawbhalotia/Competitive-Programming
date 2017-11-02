    #include<stdio.h>
    int main()
      {
      	int t,i;
      	long long one,zero;
      	char ch[100001],*j;
      	scanf("%d",&t);
      	for(i=0;i<t;i++)
      	  {
      	  	scanf("%s",ch);
      	  	one=0;
      	  	zero=0;
      	  	j=ch;
      	  	while(*j!='\0')
      	  	  {
      	  	  	if(*j=='1')
      	  	  	  one++;
      	  	  	else
      	  	  	  zero++;
      	  	  	j++;
    		  }
    		if(one==1 || zero==1)
    		  printf("Yes\n");
    		else 
    		  printf("No\n");
    		}
      } 