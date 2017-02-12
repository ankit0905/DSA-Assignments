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
	int i,n;
	scanf("%d",&n);
	int id[n];
	for(i=0; i<n; i++){
		scanf("%d",&id[i]);
	}
	merge_sort(id,0,n-1);
	int ans = id[0], ct = 1, max = 1;
	for(i=1; i<n; i++){
		if(id[i] == id[i-1]){
			ct++;
		}
		else{
			if(ct > max){
				max = ct;
				ans = id[i-1];
				ct = 1;
			}
		}
	}
	if(ct > max){
		max = ct;
		ans = id[n-1];
	}
	printf("%d\n",ans);
	return 0;
}
