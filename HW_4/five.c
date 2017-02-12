#include <stdio.h>

int find(int arr[], int lo, int hi)
{
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(lo == hi)
			return lo;
		if(mid < hi && arr[mid] > arr[mid+1])
			return mid;
		else if(mid > lo && arr[mid] < arr[mid-1])
			return mid-1;
		else if(arr[lo] >= arr[mid])
			hi = mid-1;
		else
			lo = mid+1;
	}
	return -1;
}

int binary_search(int arr[], int lo, int hi, int key)
{
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] < key){
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
	int n,i,key;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	scanf("%d",&key);
	int pivot = find(arr,0,n-1), idx;
	if(pivot == -1){
		idx = binary_search(arr,0,n-1,key);
		if(idx != -1){
			printf("%d\n",idx);
			return 0;
		}
	}
	else{
		idx = binary_search(arr,0,pivot,key);
		if(idx != -1){
			printf("%d\n",idx);
			return 0;
		}
		idx = binary_search(arr,pivot+1,n-1,key);
		if(idx != -1){
			printf("%d\n",idx);
			return 0;
		}
	}
	printf("Not Found\n");
	return 0;
}
