#include <stdio.h>

int cte=0, cto=0;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void partitionEvenOdd(int arr[], int n)
{
	int i,idx = 0;
	for(i=0; i<n; i++){
		if(arr[i]%2 == 0){
			swap(&arr[i],&arr[idx]);
			idx++;
		}
	}
}

int main()
{	
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d",&arr[i]);
		if(arr[i]%2==0)
			cte++;
		else
			cto++;
	}
	partitionEvenOdd(arr,n);
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
	return 0;
}
