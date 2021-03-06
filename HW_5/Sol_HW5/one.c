#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int* arr, int n)
{
	int i,j;
	for(i=0; i<n; i++){
		int min = arr[i], idx = i;
		for(j=i; j<n; j++){
			if(arr[j] < min){
				min = arr[j];
				idx = j;
			}
		}
		swap(&arr[i],&arr[idx]);
	}
}

void BBS(int* arr, int n)
{
	int lo=0, hi=n-1, j, fl=0, idx;
	while(lo<=hi){
		int min = arr[lo], max = arr[hi];
		if(fl==0){
			idx = hi;
			for(j=lo; j<=hi; j++){
				if(arr[j] > max){
					max = arr[j];
					idx = j;
				}
			}
			swap(&arr[hi],&arr[idx]);
			hi--;	
			fl=1;
		}
		else{
			idx = lo;
			for(j=hi; j>=lo; j--){
				if(arr[j] < min){
					min = arr[j];
					idx = j;
				}
			}
			swap(&arr[lo],&arr[idx]);
			lo++;
			fl=0;
		}
	}
}

void insertion_sort(int* arr, int n)
{
	int i;
	for(i=1; i<n; i++){
		int j = i-1;
		int ele = arr[j+1];
		while(arr[j] > ele && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	} 
}

int main(int argc, char* argv[])
{
	int n,i;
    clock_t start_t, end_t;
    double total_t;
    
    if(argc < 3){
    	printf("USAGE: ./a.out size sort-type\n");
    	return 0;
    }
    
    start_t = clock();
    n = atoi(argv[1]);
	int* arr = (int*)malloc(sizeof(int)*n);
	srand(time(NULL));
	
	printf("Unsorted Array: \n");
	for(i=0; i<n; i++){
		arr[i] = rand()%10000001;
	}
	for (i=0; i<10 && i<n; i++)
		printf("%d ", arr[i]);
	printf("\n\nSorted Array:\n");
	if(strcmp(argv[2], "insertion") == 0){
		insertion_sort(arr, n);
		for(i=0; i<10 && i<n; i++)
			printf("%d ",arr[i]);	
		end_t = clock();
	}
	else if(strcmp(argv[2], "BBS") == 0){
		BBS(arr, n);
		for(i=0; i<10 && i<n; i++)
			printf("%d ",arr[i]);	
		end_t = clock();
	}
	else if(strcmp(argv[2], "bubble") == 0){
		bubble_sort(arr, n);
		for(i=0; i<10 && i<n; i++)
			printf("%d ",arr[i]);	
		end_t = clock();
	}
	printf("\n\n");
	total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	printf("Time taken by %s sort = %lf\n",argv[2],total_t);
	//free(arr);
	return 0;
}
