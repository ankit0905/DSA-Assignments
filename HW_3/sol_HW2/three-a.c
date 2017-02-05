#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	m=n;
	int rows = n, cols = n;
	int *arr[n];
	for(i=0; i<n; i++)
		arr[i] = (int*)malloc(n*sizeof(int));
	int r=0, c=0, num=1;
	while(r<n && c<m){
		for(i=c; i<m; i++){
			arr[r][i]=num++;
		}
		r++;
		for(i=r; i<n; i++){
			arr[i][m-1]=num++;
		}
		m--;
		if(r<n){
			for(i=m-1; i>=c; i--){
				arr[n-1][i]=num++;
			}
			n--;
		}
		if(c<n){
			for(i=n-1; i>=r; i--){
				arr[i][c]=num++;
			}
			c++;
		}
	}
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

