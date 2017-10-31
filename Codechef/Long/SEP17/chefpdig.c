#include<stdio.h>
#include<string.h>
int main()
{
	int t,j;
	long i;
	scanf("%d",&t);
	while(t--)
	{
		char a[100015];
		scanf("%s",a);
		long b[11]={},c[27]={};
		long k=strlen(a);
		for(i=0;i<k;i++)
		{
			b[a[i]-48]++;
		}
		if(b[6]>0)
		{
			b[6]--;
			for(i=5;i<=9;i++)
			{
				if(b[i]>0)
				{
					c[i-4]++;
				}
			}
			b[6]++;
		}
		if(b[7]>0)
		{
			b[7]--;
			for(i=0;i<=9;i++)
			{
				if(b[i]>0)
				{
					c[i+6]++;
				}
			}
			b[7]++;
		}
		if(b[8]>0)
		{
			b[8]--;
			for(i=0;i<=9;i++)
			{
				if(b[i]>0)
				{
					c[i+16]++;
				}
			}
			b[7]++;
		}
		if(b[0]>0 && b[9]>0)
		{
			c[26]++;
		}
		for(j=1;j<=26;j++)
		{
			if(c[j]>0)
			{
				printf("%c",j+64);
			}
		}
		printf("\n");
	}
}