#include <stdio.h>
#include <math.h>

typedef struct{
	int row;
	int col;
}queen;

queen list[8]; 

int check(queen q1, queen q2)
{
	int rowDiff = abs(q1.row-q2.row);
	int colDiff = abs(q1.col-q2.col);
	if(rowDiff == colDiff || rowDiff == 0 || colDiff == 0)
		return 0;
	else
		return 1;
}

int main()
{
	int board[8][8], Qct=0, i, j;
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			scanf("%d",&board[i][j]);
			if(board[i][j]==1){
				list[Qct].row=i;
				list[Qct].col=j;
				Qct++;
			}
		}
	}
	int safe = 1;
	for(i=0; i<Qct; i++){
		for(j=i+1; j<Qct; j++){
			if(!check(list[i], list[j])){
				safe = 0;
				break;
			}
		}
		if(!safe)
			break;
	}
	if(!safe){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
	return 0;
}
