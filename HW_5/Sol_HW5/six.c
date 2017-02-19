#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int binary_search(int arr[], int lo, int hi, int x)
{
	while(lo <= hi){
		int mid = lo + (hi-lo)/2;
		if(lo == hi && arr[lo] == x){
			return lo;
		}
		else if(hi == lo+1){
			if(arr[lo] == x){
				return lo;
			}
			if(arr[hi] == x){
				return hi;
			}
		}
		if(arr[mid] == x){
			hi = mid;
		}
		else if(arr[mid] < x){
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	return -1;
}

int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int A1[n], A2[m], tmp[n], vis[n];
	for(i=0; i<n; i++){
		scanf("%d",&A1[i]);
		tmp[i] = A1[i];
		vis[i] = 0;
	}
	for(i=0; i<m; i++){
		scanf("%d",&A2[i]);
	}
	qsort(tmp,n,sizeof(int),compare);
	int idx = 0;
	for(i=0; i<m; i++){
		int index = binary_search(tmp, 0, n-1, A2[i]);
		if(index == -1)
			continue;
		for(j=index; (j<n && tmp[j]==A2[i]); j++){
			A1[idx++] = tmp[j];
			vis[j] = 1;
		}
	}
	for(i=0; i<n; i++){
		if(vis[i] == 0)
			A1[idx++] = tmp[i];
	}
	for(i=0; i<n; i++){
		printf("%d ",A1[i]);
	}
	printf("\n");
	return 0;
}
