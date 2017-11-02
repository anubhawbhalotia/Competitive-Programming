#include <stdio.h>
#include <string.h>
 
int main(){
 
	int i, so, st, n, count ,k , s;
	char input[100];
	
	scanf("%d",&s);
	for(count=0;count<s;count++){
	
	scanf("%s",input);
	n=strlen(input);
	for(i=0;i<n;i++){
		so=0; st=0;
		
		k=input[i]-'0';
		if(k==1) so++;
		if(k==0) st++;
	}
	
		if(so>st) printf("WIN\n");
		else printf("LOSE\n");
	
	}
	
	return 0;
}