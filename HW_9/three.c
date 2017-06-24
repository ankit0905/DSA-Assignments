#include <stdio.h>

int pos[][2] = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};

int main()
{
	int arr[9][9],i,j,k;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int solved = 1;
	int fl[9]={0};
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			fl[j]=0;
		}
		for(j=0; j<9; j++){
			if(fl[arr[i][j]-1]==0){
				fl[arr[i][j]-1]=1;
			}
			else{
				solved=0;
				break;
			}
		}
		if(!solved)
			break;
	}
	for(i=0; i<9 && solved; i++){
		for(j=0; j<9; j++){
			fl[j]=0;
		}
		for(j=0; j<9; j++){
			if(fl[arr[j][i]-1]==0){
				fl[arr[j][i]-1]=1;
			}
			else{
				solved = 0;
				break;
			}
		}
		if(!solved)
			break;
	}
	int r,c;
	for(i=0; i<9 && solved; i++){
		r = pos[i][0];
		c = pos[i][1];
		for(j=0; j<9; j++){
			fl[j]=0;
		}
		for(j=0; j<3; j++){
			for(k=0; k<3; k++){
				if(fl[arr[r+j][c+k]-1]==0){
					fl[arr[r+j][c+k]-1]=1;
				}
				else{
					solved = 0;
					break;
				}
			}
			if(!solved)
				break;
		}
	}
	if(solved)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
