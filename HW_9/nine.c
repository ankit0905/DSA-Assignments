#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalin(char str[])
{
	int len = strlen(str);
	int i=0, j=len-1;
	while(i<j){
		if(str[i] != str[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

int main()
{
	char str[50], tmp[50], idx = 0;
	scanf("%s",str);
	int len = strlen(str);
	int p[len][len];
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			p[i][j] = 0;
			if(i < j)
				continue;
			else if(i == j){
				p[i][j] = 1;
			}
			else{
				idx = 0;
				for(k=i; k<=j; k++){
					tmp[idx++] = str[k];
				}
				tmp[idx] = '\0';
			}
		}
	}
	
	return 0;
}
