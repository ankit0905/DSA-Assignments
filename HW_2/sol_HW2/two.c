#include <stdio.h>

#define ROWS 6
#define COLS 6

int main()
{
	int matrix[ROWS][COLS], count=0, i, j;
	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			scanf("%d",&matrix[i][j]);
			if(matrix[i][j]!=0){
				count++;
			}
		}
	}
	if(count>=10){
		printf("Matrix is not sparse");
		return 0;
	}
	else{
		int sparseMatrix[count][3], index=0;
		for(i=0; i<ROWS; i++){
			for(j=0; j<COLS; j++){
				if(matrix[i][j]!=0){
					sparseMatrix[index][0] = i;
					sparseMatrix[index][1] = j;
					sparseMatrix[index][2] = matrix[i][j];
					index++;
				}
			}
		}
		printf("\t\trow\tcol\tvalue\n");
		for(i=0; i<count; i++){
			if(i==0)
				printf("Array[0]\t%d\t%d\t%d\n",sparseMatrix[i][0],sparseMatrix[i][1],sparseMatrix[i][2]);
			else{
				printf("     [%d]\t%d\t%d\t%d\n",i,sparseMatrix[i][0],sparseMatrix[i][1],sparseMatrix[i][2]);
			}
		}
		//Code for transpose matrix to be added
		int transpose[count][3];
		for(i=0; i<count; i++){
			transpose[i][0]=sparseMatrix[i][1];
			transpose[i][1]=sparseMatrix[i][0];
			transpose[i][2]=sparseMatrix[i][2];
		}
		for(i=0; i<count; i++){
			int minr = transpose[i][0], minc = transpose[i][0], idx = i;
			for(j=i; j<count; j++){
				if(transpose[j][0] < minr){
					minr = transpose[j][0];
					minc = transpose[j][1];
					idx = j;
				}
				else if(transpose[j][0] == minr && transpose[j][1] < minc){
					minr = transpose[j][0];
					minc = transpose[j][1];
					idx = j;
				}
			}
			int tmpr = minr, tmpc = minc, val = transpose[idx][2];
			transpose[idx][0] = transpose[i][0];
			transpose[idx][1] = transpose[i][1];
			transpose[idx][2] = transpose[i][2];
			transpose[i][0] = minr;
			transpose[i][1] = minc;
			transpose[i][2] = val;
		}
		printf("\n");
		printf("\t\trow\tcol\tvalue\n");
		for(i=0; i<count; i++){
			if(i==0)
				printf("Array[0]\t%d\t%d\t%d\n",transpose[i][0],transpose[i][1],transpose[i][2]);
			else{
				printf("     [%d]\t%d\t%d\t%d\n",i,transpose[i][0],transpose[i][1],transpose[i][2]);
			}
		}
	}
	return 0;
}
