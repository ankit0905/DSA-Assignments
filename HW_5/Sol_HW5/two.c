#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(long int arr[], int lo, int mid, int hi)
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

void merge_sort(long int arr[], int lo, int hi)
{
	if(lo>=hi)
		return;
	int mid = lo+(hi-lo)/2;
	merge_sort(arr,lo,mid);
	merge_sort(arr,mid+1,hi);
	merge(arr,lo,mid,hi);
}

void swap(long int* a, long int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void comb_sort(long int arr[], int n)
{
	int gap = n, fl = 1, i;
	while(gap!=1 || fl==1){
		fl = 0;
		gap = (gap*10)/13;
		if(gap < 1)
			gap = 1;
		for(i=0; i<n-gap; i++){
			if(arr[i] > arr[i+gap]){
				swap(&arr[i], &arr[i+gap]);
				fl=1;
			}
		} 
	}
}

int partition(long int arr[], int lo, int hi)
{
	int x = arr[hi];
	int i = lo-1, j;
	for(j=lo; j<=hi-1; j++){
		if(arr[j] <= x){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[hi]);
	return i+1;
}

void quickSort(long int arr[], int lo, int hi)
{
	if(lo < hi){
		int p = partition(arr, lo, hi);
		quickSort(arr, lo, p-1);
		quickSort(arr, p+1, hi);
	}
}

int main(int argc, char* argv[])
{
	long int n,i;
	long int* arr;
	clock_t start_t, end_t;
	double total_t;
	
	if(argc < 3){
		printf("Usage: ./a.out size sort-type\n");
		return 0;
	}
	
	start_t = clock();
	n = atoi(argv[1]);
	arr = (long int*)malloc(sizeof(long int)*n);
	srand(time(NULL));
	
	for(i=0; i<n; i++){
		arr[i] = rand() % 10000001;
	}
	printf("Unsorted array : \n");
	for (i = 0; i < 10; i++)
		printf("%ld ", arr[i]);
	printf("\n\n");
	printf("Sorted array\n");
	if(strcmp(argv[2], "comb") == 0){
		comb_sort(arr, n);
		for(i=0; i<10 && i<n; i++)
			printf("%ld ",arr[i]);
		end_t = clock();
	}
	else if(strcmp(argv[2], "merge") == 0){
		merge_sort(arr, 0, n-1);
		for(i=0; i<10 && i<n; i++)
			printf("%ld ",arr[i]);
		end_t = clock();
	}
	else if(strcmp(argv[2], "quick") == 0){
		quickSort(arr,0,n-1);
		for(i=0; i<10 && i<n; i++)
			printf("%ld ",arr[i]);
		end_t = clock();
	}
	printf("\n\n");
	total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	printf("Time taken by %s sort = %lf\n",argv[2],total_t);
	free(arr);
	return 0;
}
