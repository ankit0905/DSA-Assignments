#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	int lo=0, hi=n-1;
	if(n==1){
		printf("0\n");
		return 0;
	}
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(mid==0 && arr[mid]>=arr[mid+1] || mid==n-1 && arr[mid]>=arr[mid-1]){
			printf("%d\n",mid);
			break;
		}
		else if(arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1]){
			printf("%d\n",mid);
			break;	
		}
		else if(arr[mid]<arr[mid+1]){
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	return 0;
}
