#include<stdio.h>
int main()
  {
    long t,tc,c,max=0,z;
    char *p,s[100001];
    scanf("%ld",&t);
    for(tc=0;tc<t;tc++)
      {
        scanf("%s",s);
        p=s;
        c=0;
        z=0;
        max=0;
        while(*p!='\0')
          {
            if(z>max)
              max=z;
            if(*p=='=')
              {
                p++;
                continue;
              }
            if(c==1 && *p=='<')
              {
                z++;
                p++;
                continue;
              }
            else
              if(c==2 && *p=='>')
                {
                  z++;
                  p++;
                  continue;
                }
            if(*p=='<')
              c=1;
            else if(*p=='>')
                   c=2;
            z=1;
            p++;
          }
        if(z>max)
          max=z;
        printf("%ld\n",max+1);
      }
  }