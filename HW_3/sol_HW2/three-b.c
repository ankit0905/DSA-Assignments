//NOT COMPLETE (have to make it work for "word")
#include <stdio.h>
#include <string.h>

int found[50], xfound[50], it = 0, xit = 0;

void searchAndAdd(char* pattern, char* line, int lineNo)
{
	if(strstr(line, pattern)){
		found[it++] = lineNo;
	}
	else{
		xfound[xit++] = lineNo;
	}
}

int main(int argc, char* argv[])
{
	FILE* fp;
	char ch, fileName[15], pattern[20], contents[50][50];
	int flag, row = 0, col = 0, j;
	if(argc <= 2){
		printf("Not enough arguments\n");
		return 0;
	}
	else if(argc == 3){
		strcpy(fileName,argv[2]);
		strcpy(pattern,argv[1]);
		flag = 1;
	}
	else{
		strcpy(fileName,argv[3]);
		strcpy(pattern,argv[2]);
		flag = 2;
	}
	fp = fopen(fileName,"r");
	do{
		ch = (char)getc(fp);
		if(ch == '\n'){
			contents[row][col]='\0';
			row++;
			col = 0;
		}
		else{
			contents[row][col++]=ch;
		}
	}while(ch!=EOF);
	for(j=0; j<row; j++){
		searchAndAdd(pattern, contents[j], j);
	}
	if(flag == 1){
		for(j=0; j<it; j++){
			printf("%d\n%s\n",found[j]+1,contents[j]);
		}
	}
	else{
		for(j=0; j<xit; j++){
			printf("%d\n%s\n",xfound[j]+1,contents[j]);
		}
	}
	return 0;
}
