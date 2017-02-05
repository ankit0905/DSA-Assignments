#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char* lines = NULL, *fileName, *dir;
	if(argc == 4){
		lines = argv[1];
		fileName = argv[2];
		dir = argv[3];
	}
	else if(argc == 3){
		lines = "-10";
		fileName = argv[1];
		dir = argv[2];
	}
	else{
		printf("Too few arguments\n");
		return 0;
	}
	FILE* fp = fopen(fileName,"r");
	int numLines = atoi(lines+1);
	if(dir[0] == 't'){
		int lineCount = 0;
		char ch;
		while(lineCount < numLines){
			ch = fgetc(fp);
			if(ch == -1){
				break;
			}
			else if(ch == '\n'){
				printf("\n");
				lineCount++;
			}
			else{
				printf("%c",ch);
			}
		}	
	}
	else{
		int totLines = 0;
		while(1){
			char ch = fgetc(fp);
			if(ch == '\n'){
				totLines++;
			}	
			else if(ch == -1){
				break;
			}
		}
		fclose(fp);
		fp = fopen(fileName,"r");
		int currLine = 1;
		int st = totLines-numLines+1;
		if(st <= 0)
			st = 1;
		while(1){
			char ch = fgetc(fp);
			if(currLine >= st && ch != -1){
				printf("%c",ch);
			}
			if(ch == '\n'){
				currLine++;
			}
			else if(ch == -1)
				break;
		}
		fclose(fp);
	}
	return 0;
}
