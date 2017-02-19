#include <stdio.h>

typedef struct{
	int num;
	int idx;
}pair;

void merge(pair arr[], int lo, int mid, int hi, int ct[])
{
	int sz1 = mid-lo+1, sz2 = hi-mid, i, j, k, it, count=0;
	pair left[sz1], right[sz2];
	for(i=0; i<sz1; i++)
		left[i] = arr[lo+i];
	for(i=0; i<sz2; i++)
		right[i] = arr[mid+1+i];
	i = j = 0;
	k = lo;
	while(i<sz1 && j<sz2){
		if(left[i].num <= right[j].num)
			arr[k++] = left[i++];
		else{
			for(it = i; it < sz1; it++){
				ct[left[it].idx]++;
			}
			arr[k++] = right[j++];
		}
	}
	while(i<sz1)
		arr[k++] = left[i++];
	while(j<sz2)
		arr[k++] = right[j++];
}

void merge_sort(pair arr[], int lo, int hi, int ct[])
{
	if(lo>=hi)
		return;
	int mid = lo+(hi-lo)/2;
	merge_sort(arr,lo,mid,ct);
	merge_sort(arr,mid+1,hi,ct);
	merge(arr,lo,mid,hi,ct);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int count[n];
	pair arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i].num);
		arr[i].idx = i;
		count[i] = 0;	
	}
	merge_sort(arr, 0, n-1, count);
	for(i=0; i<n; i++)
		printf("%d ",count[i]);
	printf("\n");
	return 0;
}
