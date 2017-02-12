#include <stdio.h>

void merge(int arr[], int lo, int mid, int hi, int id[])
{
	int sz1 = mid-lo+1, sz2 = hi-mid, i, j, k;
	int left[sz1], lid[sz1], rid[sz2],right[sz2];
	for(i=0; i<sz1; i++){
		left[i] = arr[lo+i];
		lid[i] = id[lo+i];
	}
	for(i=0; i<sz2; i++){
		right[i] = arr[mid+1+i];
		rid[i] = id[mid+i+1];
	}
	i = j = 0;
	k = lo;
	while(i<sz1 && j<sz2){
		if(left[i] >= right[j]){
			arr[k] = left[i];
			id[k++] = lid[i];
			i++;
		}
		else{
			arr[k] = right[j];
			id[k++] = rid[j];
			j++;
		}
	}
	while(i<sz1){
		arr[k] = left[i];
		id[k++] = lid[i];
		i++;
	}
	while(j<sz2){
		arr[k] = right[j];
		id[k++] = rid[j];
		j++;
	}
}

void merge_sort(int arr[], int lo, int hi, int id[])
{
	if(lo>=hi)
		return;
	int mid = lo+(hi-lo)/2;
	merge_sort(arr,lo,mid,id);
	merge_sort(arr,mid+1,hi,id);
	merge(arr,lo,mid,hi,id);
}

int main()
{
	int i,n;
	scanf("%d",&n);
	int arr[n],id[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
		id[i] = i;
	}
	merge_sort(arr,0,n-1,id);
	printf("%d\n",arr[0]);
	printf("%d\n",id[0]+1);
	return 0;
}
