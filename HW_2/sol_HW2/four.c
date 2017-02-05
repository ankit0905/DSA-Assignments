#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char message[105];
	int i,key;
	scanf("%[^\n]",message);
	scanf("%d",&key);
	int len = strlen(message);
	char ciphertext[key][50];
	int row = 0, col = 0, ct = 0;
	for(i=0; i<len; i++){
		if(row == key){
			row = 0;
			col++;
		}
		if(message[i]!=' '){
			ciphertext[row++][col]=message[i];
			ct++;
		}
	}
	int max = ceil((double)ct/key);
	int mod = ct%key;
	int count = 0;
	row = col = 0;
	int end = max;
	while(count < ct){
		if(col == end && (row < mod || mod == 0) || row >= mod  && col == end-1 && mod!=0){
			row++;
			col = 0;
		}
		printf("%c",ciphertext[row][col]);
		count++;
		col++;
	}
	return 0;
}/*
NHGATET
OIISSM
TNSIES
*/
