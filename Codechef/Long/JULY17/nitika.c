    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int main()
      {
        int t,tc,space,z;
        char *p,c[35],s[35];
        scanf("%d ",&t);
        fflush(stdin);
        for(tc=0;tc<t;tc++)
          {
            fflush(stdin);
            space=0;
            z=0;
            gets(c);
            //puts(c);
            fflush(stdin);
            p=c;    
            while(*p!='\0')
              {
                if(*p==' ')
                  space++;
                p++;
              }
            p=c;
            
            if(space==1)
              {
                *(s+0)=*(p+0);
                if(*s>=97)
                  *s-=32;
                *(s+1)='.';
                *(s+2)=' ';
                z=3;
                while(*p!=' ')
                  p++;
                p++;
              }
            if(space==2)
              {
                *(s+0)=*(p+0);
                if(*s>=97)
                  *s-=32;
                *(s+1)='.';
                *(s+2)=' ';
                while(*p!=' ')
                  p++;
                p++;
                *(s+3)=*p;
                if(*(s+3)>=97)
                  *(s+3)-=32;
                *(s+4)='.';
                *(s+5)=' ';
                z=6;
                while(*p!=' ')
                  p++;
                p++;
              }
            *(s+z)=*p;
            if(*(s+z)>=97)
              *(s+z)-=32;
            z++;
            p++;
            while(*p!='\0')
              {
                if(*p<97)
                  *p+=32;
                *(s+z)=*p;
                z++;
                p++;
              }
            *(s+z)='\0';
            puts(s);
          }
      } 