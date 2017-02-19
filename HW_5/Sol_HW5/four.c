#include <stdio.h>

typedef struct{
	int num;
	int idx;
}pair;

int merge(pair arr[], int lo, int mid, int hi)
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
				printf("(%d %d),",left[it].idx,right[j].idx);
			}
			count += (sz1-i);
			arr[k++] = right[j++];
		}
	}
	while(i<sz1)
		arr[k++] = left[i++];
	while(j<sz2)
		arr[k++] = right[j++];
	return count;
}

int merge_sort(pair arr[], int lo, int hi)
{
	if(lo>=hi)
		return 0;
	int mid = lo+(hi-lo)/2;
	int ct1 = merge_sort(arr,lo,mid);
	int ct2 = merge_sort(arr,mid+1,hi);
	return merge(arr,lo,mid,hi)+ct1+ct2;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	pair arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i].num);
		arr[i].idx=i;
	}
	printf("\nNumber of Inversions: %d\n",merge_sort(arr,0,n-1));
	return 0;
}
