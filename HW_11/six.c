#include <stdio.h>
#include <limits.h>

int main()
{
	int n,i,j,N,tmp;
	scanf("%d",&n);
	int d[n];
	for(i=0; i<n; i++){
		scanf("%d",&d[i]);
	}
	scanf("%d",&N);
	int dp[N+1];
	dp[0] = 0;
	for(i=1; i<=N; i++)
		dp[i] = INT_MAX;
	for(i=1; i<=N; i++){
		for(j=0; j<n; j++){
			if(d[j] <= i){
				tmp = dp[i-d[j]];
				if(tmp != INT_MAX && tmp + 1 < dp[i])
					dp[i] = tmp + 1;
			}
		}
	}
	printf("%d\n",dp[N]);
	return 0;
}
