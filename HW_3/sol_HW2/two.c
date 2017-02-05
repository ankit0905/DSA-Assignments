#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lookup[] = {0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};

char* convert(char* word)
{
	int len = strlen(word), i, j=0, k=1, l=0;
	char str[len+4], seq[len+4];
	char* code = (char*)malloc(sizeof(char)*5);
	for(i=0; i<len; i++){
		char ch = word[i];
		if(i!=0 && (ch >= 65 && ch <= 90 || ch >=97 && ch<=122)){
			ch = toupper(ch);
			int dig = lookup[ch-65];
			str[j++] = dig+48;
		}
		else if(i==0){
			str[j++] = toupper(ch);
		}
	}
	str[j] = '\0';
	seq[0] = str[0];
	for(i=1; i<j; i++){
		if(str[i]==str[i+1]){
			seq[k++]=str[i];
			i++;
		}
		else{
			seq[k++]=str[i];
		}
	}
	seq[k]='\0';
	for(i=0; i<k && l<4; i++){
		if(seq[i]=='0'){
			continue;
		}
		else{
			code[l++]=seq[i];
		}
	}
	while(l<4){
		code[l++]='0';
	}
	code[l]='\0';
	return code;
}

int main()
{	
	char* fileName = (char*)malloc(sizeof(char)*15);
	char* word = (char*)malloc(sizeof(char)*10);
	scanf("%s %s",fileName,word);
	char* key = convert(word);
	FILE* fp;
	fp = fopen(fileName, "r");
	char ch,contents[50][100];
	int r = 0, c = 0, i, j;
	do{
		ch = fgetc(fp);
		if(ch == EOF){
			contents[r][c] = 0;
		}
		else if(ch == '\n'){
			contents[r][c] = 0;
			r++;
			c=0;
		}
		else{
			contents[r][c++] = ch;
		}
	}while(ch!=EOF);
	for(i=0; i<r; i++){
		char tmp[20], idx=0;
		char* code;
		int len = strlen(contents[i]);
		for(j=0; j<len; j++){
			if(contents[i][j] == ' '){
				tmp[idx]=0;
				code = convert(tmp);
				if(strcmp(code,key)==0){
					printf("%s\n",contents[i]);
					break;
				}
				idx=0;
			}
			else{
				tmp[idx++]=contents[i][j];
				if(j == len-1){
					tmp[idx]=0;
					code = convert(tmp);
					if(strcmp(code,key)==0){
						printf("%s\n",contents[i]);
						break;
					}
					idx=0;
				}
			}
		}
	}
	fclose(fp);
	return 0;
}
