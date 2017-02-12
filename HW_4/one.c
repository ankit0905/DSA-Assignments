//Not complete
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	char author[20];
	int edition;
	int ISBN;
	int price;
}Book;

void insertion_sort(int arr[], int n)
{
	for(int i=1; i<n; i++){
		int j = i-1;
		int ele = arr[j+1];
		while(arr[j] > ele && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = ele;
	} 
}

int main()
{
	int n,i;
	time_t t;
	scanf("%d",&n);
	FILE* fp = fopen("test.txt","w");
	int ct = 0;
	srand((unsigned) time(&t));
	while(ct!=n){
		int num = rand()%100001;
		if(num == 0)
			continue;
		else{
			ct++;
			fprintf(fp,"%d ",num);
		}
	}
	fclose(fp);
	fp = fopen("test.txt","r");
	int numbers[n];
	for(i=0; i<n; i++){
		fscanf(fp,"%d",&numbers[i]);
	}
	insertion_sort(numbers,n);
	/*for(i=0; i<n; i++){
		printf("%d ",numbers[i]);
	}*/
	return 0;
}
