#include <stdio.h>

void merge(int arr[], int lo, int mid, int hi)
{
	int sz1 = mid-lo+1, sz2 = hi-mid, i, j, k;
	int left[sz1], right[sz2];
	for(i=0; i<sz1; i++)
		left[i] = arr[lo+i];
	for(i=0; i<sz2; i++)
		right[i] = arr[mid+1+i];
	i = j = 0;
	k = lo;
	while(i<sz1 && j<sz2){
		if(left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while(i<sz1)
		arr[k++] = left[i++];
	while(j<sz2)
		arr[k++] = right[j++];
}

void merge_sort(int arr[], int lo, int hi)
{
	if(lo>=hi)
		return;
	int mid = lo+(hi-lo)/2;
	merge_sort(arr,lo,mid);
	merge_sort(arr,mid+1,hi);
	merge(arr,lo,mid,hi);
}

int main()
{
	int n,X,i;
	scanf("%d %d",&n,&X);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	merge_sort(arr,0,n-1);
	for(i=0; i<n; i++){
		int ele = arr[i];
		int key = X-ele, lo=0, hi=n-1;
		int it=0;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			if(arr[mid]==key && i!=mid){
				printf("Yes\n");
				return 0;
			}
			else if(arr[mid]==key){
				if(arr[mid+1]==key || arr[mid-1]==key){
					printf("Yes\n");
					return 0;
				}
				else{
					break;
				}
			}
			else if(arr[mid]<key){
				lo = mid+1;
			}
			else if(arr[mid]){
				hi = mid-1;
			}
		}
	}
	printf("No\n");
	return 0;
}
