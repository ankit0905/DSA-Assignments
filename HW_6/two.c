#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int n,m,i,ans=0;
	scanf("%d %d",&n,&m);
	int players[n];
	for(i=0; i<n; i++)
		scanf("%d",&players[i]);
	qsort(players,n,sizeof(int),compare);
	while(players[n-m]!=0){
		ans += players[n-m];
		int tmp = players[n-m];
		for(i=n-m; i<n; i++)
			players[i] -= tmp;
		qsort(players,n,sizeof(int),compare);
	}
	printf("%d\n",ans);
	return 0;
}
