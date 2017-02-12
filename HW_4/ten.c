#include <stdio.h>

int check(int X[], int dist, int n, int k)
{
	int count = 1, i;
	int vis = X[0];
	for(i=1; i<n; i++){
		if(X[i]-vis >= dist){
			count++;
			vis = X[i];
		}
	}
	if(count >= k)
		return 1;
	else
		return 0;
} 

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
	int i,t,n,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&c);
		int position[n];
		for(i=0; i<n; i++){
			scanf("%d",&position[i]);
		}
		merge_sort(position,0,n-1);
		int mid, lo = 0, hi = position[n-1]-position[0]+1;
		int ans=0;
		while(lo+1<hi){
			mid = lo + (hi-lo)/2;
			if(check(position,mid,n,c)){
				lo = mid;
				ans = (ans > mid)?ans:mid;
			}
			else
				hi = mid;
		}
		printf("%d\n",ans);
	}
	return 0;
}
