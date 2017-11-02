#include<stdio.h>
#include<string.h>
int main()
  {
    int t,tc,z,d;
    char *c,ch[100000];
    scanf("%d",&t);
    fflush(stdin);
    for(tc=1;tc<=t;tc++)
      {
        scanf("%s",ch);
        d=0;
        z=0;
        c=ch;
        while((*c)!='\0')
          {
            if((*c)=='1')
              z++;
            c++;
          }
        c=ch;
        while((*c)!='1' && (*c)!='\0')
          {
            c++;
          }
        while((*c)=='1' && (*c)!='\0')
          {
            d++;
            c++;
          }
        if(d==z && d!=0)
          printf("YES\n");
        else
          printf("NO\n");
      }
  }