#include <stdio.h>

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int valid(int r, int c, int n)
{
	if(r<0 || c<0 || r>=n || c>=n)
		return 0;
	else
		return 1;
}

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	int matrix[n][n], sum[n][n];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%d",&matrix[i][j]);
			if(j!=0)
				sum[i][j] = sum[i][j-1]+matrix[i][j];
			else
				sum[i][j] = matrix[i][j];
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i!=0)
				sum[i][j] = sum[i-1][j]+sum[i][j];
			//printf("%d ", sum[i][j]);
		}
		//printf("\n");
	}
	int ans = 0;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			int m = 1+min(i,j);
			for(k=1; k<=m; k++){
				int tmp = sum[i][j];
				if(valid(i,j-k,n))
					tmp -= sum[i][j-k];
				if(valid(i-k,j,n))
					tmp -= sum[i-k][j];
				if(valid(i-k,j-k,n))
					tmp += sum[i-k][j-k];
				if(tmp > ans)
					ans = tmp;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
