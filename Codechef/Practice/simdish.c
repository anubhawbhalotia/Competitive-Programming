#include<stdio.h>
#include<string.h>
int main()
  {
    int c,i,j,k,t;;
    char a[4][11],b[4][11];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
      {
        scanf("%s %s %s %s",a[0],a[1],a[2],a[3]);
        scanf("%s %s %s %s",b[0],b[1],b[2],b[3]);
        c=0;
        for(j=0;j<4;j++)
          {
            for(k=0;k<4;k++)
              {
                if(strcmp(a[j],b[k])==0)
                  {
                    c++;
                    break;
                  }
              }
          }
        if(c>=2)
          printf("similar\n");
        else
          printf("dissimilar\n");
      }
  }