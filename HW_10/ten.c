#include <stdio.h>

int main()
{
	int m,i,j,x,ele,ct=0,fl[10004];
	scanf("%d",&m);
	int demand[m];
	for(i=0; i<m; i++){
		scanf("%d",&demand[i]);
	}
	scanf("%d",&n);
	for(i=0; i<n; i++){
		for(j=0; j<=1000; j++)	
			fl[j] = 0;
		scanf("%d",&x);
		for(int j=0; j<x; j++){
			scanf("%d",&ele);
			fl[ele]++;
		}
		for(j=0; j<m; j++){
			if(fl[demand[j]] == 0){
				break;
			}
		}
		if(j == m)
			ct++;
	}
	printf("%d\n",ct);
	return 0;
}
