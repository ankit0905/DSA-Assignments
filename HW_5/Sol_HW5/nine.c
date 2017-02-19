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
		if(left[i]%10 < right[j]%10 || (left[i]%10 == right[j]%10 && left[i] < right[j])){
			arr[k++] = left[i++];
		}
		else{
			arr[k++] = right[j++];
		}
	}
	while(i<sz1)
		arr[k++] = left[i++];
	while(j<sz2)
		arr[k++] = right[j++];
}

void moduloMergeSort(int arr[], int lo, int hi)
{
	if(lo>=hi)
		return;
	int mid = lo+(hi-lo)/2;
	moduloMergeSort(arr,lo,mid);
	moduloMergeSort(arr,mid+1,hi);
	merge(arr,lo,mid,hi);
}

int main()
{	
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	moduloMergeSort(arr,0,n-1);
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
	return 0;
}
