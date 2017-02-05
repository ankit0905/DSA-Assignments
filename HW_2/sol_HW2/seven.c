#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int i,n,k;
	scanf("%d %d",&n,&k);
	if(k==1){
		for(i=0; i<n; i++)
			printf("1");
		printf(" ");
		for(i=0; i<n; i++)
			printf("9");
	}
	else{
		int tmp = (n-k+1);
		k-=2;
		printf("1");
		for(i=0; i<tmp; i++)
			printf("0");
		int ele = 2;
		for(i=0; i<k; i++){
			printf("%c",(char)ele+48);
			ele++;
		}
		printf(" ");
	 	for(i=0; i<tmp; i++)
			printf("9");
		ele = 8;	
		for(i=0; i<=k; i++){
			printf("%c",(char)ele+48);
			ele--;
		}
		printf("\n");
	}
	return 0;
}

