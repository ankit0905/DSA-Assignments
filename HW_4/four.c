//code to be added for comparing the 2 searches
#include <stdio.h>

int binary_search(int arr[], int n, int key)
{
	int lo=0, hi=n-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>key){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	return -1;
}

int ternary_search(int arr[], int n, int key){
	int lo=0,hi=n-1;
	while(lo<=hi){
		int m1=lo+(hi-lo)/3;
		int m2=hi-(hi-lo)/3;
		if(arr[m1] == key)
			return m1;
		else if(arr[m2] == key)
			return m2;
		if(arr[m1] > key){
			hi=m1;
		}
		else if(arr[m2] < key){
			lo=m2;
		}
		else{
			lo=m1+1;
			hi=m2-1;
		}
	}
	return -1;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	printf("%d %d\n",binary_search(arr,n,3),ternary_search(arr,n,3));
	return 0;
}


























