#include <stdio.h>

int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	int dp[n+1][r+1];
	for(int i=0; i<=n; i++){
		dp[i][0] = 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=r && j<=i; j++){
			if(j == 1)
				dp[i][j] = i;
			else if(i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	printf("%d\n",dp[n][r]);
	return 0;
}
