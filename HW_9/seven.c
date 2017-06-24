#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapifyDown(int n, int heap[][3], int idx)
{
	int ch1 = idx*2, ch2 = idx*2+1;
	while(ch1 <= n){
		if(ch2 <= n){
			if(heap[ch2][0] >= heap[ch1][0] && heap[ch2][0] > heap[idx][0]){
				swap(&heap[ch2][0],&heap[idx][0]);
				swap(&heap[ch2][1],&heap[idx][1]);
				swap(&heap[ch2][2],&heap[idx][2]);
				idx = ch2;
			}
			else if(heap[ch1][0] > heap[idx][0]){
				swap(&heap[ch1][0],&heap[idx][0]);
				swap(&heap[ch1][1],&heap[idx][1]);
				swap(&heap[ch1][2],&heap[idx][2]);
				idx = ch1;
			}
			else{
				break;
			}
		}
		else if(ch1 <= n){
			if(heap[ch1][0] > heap[idx][0]){
				swap(&heap[ch1][0],&heap[idx][0]);
				swap(&heap[ch1][1],&heap[idx][1]);
				swap(&heap[ch1][2],&heap[idx][2]);
				idx = ch1;
			}
			else{
				break;
			}
		}
		ch1 = idx*2;
		ch2 = idx*2+1;
	}
}

int delete(int heap[][3], int* n)
{
	printf("%d %d %d\n",heap[1][0],heap[1][1],heap[1][2]);
	int sz = *n;
	swap(&heap[sz][0],&heap[1][0]);
	swap(&heap[sz][1],&heap[1][1]);
	swap(&heap[sz][2],&heap[1][2]);
	(*n)--;
	sz--;
	heapifyDown(sz,heap,1);
	return heap[1][1];
}

void insert(int heap[][3], int* n, int ele, int r, int c)
{
	int sz = *n;
	(*n)++;
	sz++;
	heap[sz][0] = ele;
	heap[sz][1] = r;
	heap[sz][2] = c;
	int idx = sz, par = idx/2;
	while(idx != 1){
		if(heap[par][0] < heap[idx][0]){
			swap(&heap[par][0], &heap[idx][0]);
			swap(&heap[par][1], &heap[idx][1]);
			swap(&heap[par][2], &heap[idx][2]);
			idx = par;
			par = idx/2;
		}
		else{
			break;
		}
	}	
}

int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	int points[n][m];
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&points[i][j]);
		}
	}
	int heap[n+1][3], index[n];
	for(i=1; i<=n; i++){
		heap[i][0] = points[i-1][0];
		heap[i][1] = i-1;
		heap[i][2] = 0;
		index[i-1] = 1;
	}
	for(i=n/2; i>=1; i--){
		heapifyDown(n,heap,i);
	}
	while(n != 0){
		int row = delete(heap, &n);
		if(index[row] < m){
			insert(heap, &n, points[row][index[row]], row, index[row]);
			index[row]++;
		}
	}
	return 0;
}



































